#include "get_next_line.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] && s[i] != c) // Fix bug #1: vérifier s[i] avant de comparer
        i++;                  // sinon cela crée une boucle infini
    if (s[i] == c)
    {
        return ((char *)(s + i));
    }
    else
        return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n) // Fix bug #2: retourner void*
// pour qu'une fonction void puisse return, elle doit etre pointé avec *
{
    size_t i = 0; // Fix bug #3: copier du début vers la fin
                  // il faut commencé la chaine à 0
    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return dest;
}

size_t ft_strlen(char *s)
{
    size_t ret;

    ret = 0;
    while (*s)
    {
        ret++;
        s++;
    }
    return (ret);
}

int str_append_mem(char **s1, const char *s2, size_t size2) // Fix bug #4: double pointeur
// etant une fonction `int` il n'as pas besoin de * pour return une valeur simple
{
    if (!s1 || !*s1)
        return 0;
    size_t size1 = ft_strlen(*s1);
    if (size1 == 0) // Gérer le cas NULL, chaine a 0
        return 0;
    char *tmp = malloc(size1 + size2 + 1);
    if (!tmp)
        return (0);
    if (*s1)
    {
        ft_memcpy(tmp, *s1, size1);
        free(*s1);
    }
    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = 0;
    *s1 = tmp; // Maintenant on peut modifier le pointeur original qu'as la fin
    return (1);
}

int str_append_str(char **s1, char *s2)
{
    return (str_append_mem(s1, s2, ft_strlen(s2))); // Fix bug #5: passer s1 directement, pas besoin de tmp
}

void *ft_memmove(void *dest, const void *src, size_t n) // Retourner void*
// pour qu'une fonction void puisse return, elle doit etre pointé avec *, de même pour une variable void
{
    size_t i;

    if (dest > src)
    {
        i = n;        // Fix bug #6: utiliser n au lieu de ft_strlen, fr_strlen ne sert a rien si on connait deja la longueur
        while (i > 0) // Éviter la boucle infinie avec unsigned
        {
            i--;
            ((char *)dest)[i] = ((char *)src)[i];
        }
    }
    else if (dest == src)
        return (dest);
    else
    {
        i = 0;
        while (i < n)
        {
            ((char *)dest)[i] = ((char *)src)[i];
            i++;
        }
    }
    return (dest);
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret = NULL;
    char *tmp = ft_strchr(b, '\n');

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    while (!tmp)
    {
        if (!str_append_str(&ret, b))
            return (NULL);
        int read_ret = read(fd, b, BUFFER_SIZE);
        if (read_ret == -1)
        {
            if (ret)
                free(ret);
            return (NULL);
        }
        if (read_ret == 0) // dans le cas EOF
        {
            if (ret && ft_strlen(ret) > 0)
                return (ret);
            if (ret)
                free(ret);
            return (NULL);
        }
        b[read_ret] = '\0';
        tmp = ft_strchr(b, '\n'); // Chercher '\n' dans le nouveau buffer
    }

    // On arrive ici seulement si on a trouvé '\n'
    if (!str_append_mem(&ret, b, tmp - b + 1))
    {
        if (ret)
            free(ret);
        return (NULL);
    }

    // Sauvegarder le reste du buffer pour le prochain appel
    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
    return (ret);
}

// Test simple intégré avec debug
#include <fcntl.h>
#include <stdio.h>

int main()
{
    // Créer un fichier de test SIMPLE
    int fd_write = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(fd_write, "A\nB\nC", 5); // Fichier très simple: "A\nB\nC"
    close(fd_write);

    // Vérifier le contenu du fichier créé
    printf("=== CONTENU DU FICHIER CRÉÉ ===\n");
    fd_write = open("test.txt", O_RDONLY);
    char check_buffer[100];
    int bytes_read = read(fd_write, check_buffer, 99);
    check_buffer[bytes_read] = '\0';
    close(fd_write);
    printf("Contenu brut: [%s] (%d bytes)\n", check_buffer, bytes_read);

    // Tester get_next_line avec LIMITE de sécurité
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int i = 1;
    int max_lines = 10; // LIMITE DE SÉCURITÉ

    printf("\n=== TEST GET_NEXT_LINE (BUFFER_SIZE=%d) ===\n", BUFFER_SIZE);

    while ((line = get_next_line(fd)) != NULL && i <= max_lines)
    {
        printf("Ligne %d: [%s] (longueur: %zu)\n", i, line, ft_strlen(line));
        free(line);
        i++;
    }

    if (i > max_lines)
        printf("⚠️  ARRÊT FORCÉ - Boucle infinie détectée!\n");
    else
        printf("✅ Fin normale des tests.\n");

    close(fd);
    return (0);
}
