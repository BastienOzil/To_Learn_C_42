#include "get_next_line_explain.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    if (s[i] == c)
    {
        return ((char *)(s + i));
    }
    else
        return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    int i = 0;

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

int str_append_mem(char **s1, const char *s2, size_t size2)
{
    if (!s1 || !*s1)
        return 0;

    size_t size1 = ft_strlen(*s1);
    if (size1 == 0)
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

    *s1 = tmp;
    return (1);
}

int str_append_str(char **s1, char *s2)
{
    return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    int i;

    if (dest > src)
    {
        i = n;
        while (i > 0)
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
        if (read_ret == 0)
        {
            if (ret && ft_strlen(ret) > 0)
                return (ret);
            if (ret)
                free(ret);
            return (NULL);
        }

        b[read_ret] = '\0';
        tmp = ft_strchr(b, '\n');
    }

    if (!str_append_mem(&ret, b, tmp - b + 1))
    {
        if (ret)
            free(ret);
        return (NULL);
    }

    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);

    return (ret);
}

// ========================================
// SECTION DE TEST INTÉGRÉE
// ========================================

#include <fcntl.h>
#include <stdio.h>

/*
 * main - Fonction de test pour get_next_line
 *
 * Crée un fichier de test simple et teste la fonction get_next_line
 * avec des mesures de sécurité pour éviter les boucles infinies
 */
int main()
{
    printf("=== TEST DE GET_NEXT_LINE ===\n");
    printf("BUFFER_SIZE configuré: %d\n\n", BUFFER_SIZE);

    // ===== CRÉATION DU FICHIER DE TEST =====
    int fd_write = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd_write == -1)
    {
        printf("❌ Erreur: impossible de créer le fichier de test\n");
        return (1);
    }

    // Écriture d'un contenu simple: 3 lignes
    write(fd_write, "A\nB\nC", 5); // Fichier très simple: "A\nB\nC"
    close(fd_write);
    printf("✅ Fichier test.txt créé avec le contenu: A\\nB\\nC\n");

    // ===== VÉRIFICATION DU CONTENU CRÉÉ =====
    printf("\n=== VÉRIFICATION DU FICHIER ===\n");
    fd_write = open("test.txt", O_RDONLY);
    char check_buffer[100];
    int bytes_read = read(fd_write, check_buffer, 99);
    check_buffer[bytes_read] = '\0';
    close(fd_write);
    printf("Contenu brut lu: [%s] (%d bytes)\n", check_buffer, bytes_read);

    // ===== TEST DE GET_NEXT_LINE =====
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("❌ Erreur: impossible d'ouvrir le fichier de test\n");
        return (1);
    }

    char *line;
    int i = 1;
    int max_lines = 10; // LIMITE DE SÉCURITÉ contre les boucles infinies

    printf("\n=== TEST GET_NEXT_LINE ===\n");

    // Lecture ligne par ligne avec limite de sécurité
    while ((line = get_next_line(fd)) != NULL && i <= max_lines)
    {
        printf("Ligne %d: [%s] (longueur: %zu caractères)\n", i, line, ft_strlen(line));
        free(line); // IMPORTANT: libérer la mémoire allouée par get_next_line
        i++;
    }

    // Vérification si on a dépassé la limite (boucle infinie détectée)
    if (i > max_lines)
        printf("⚠️  ARRÊT FORCÉ - Boucle infinie détectée!\n");
    else
        printf("✅ Fin normale de la lecture (EOF atteint)\n");

    close(fd);

    // Test avec un fichier inexistant
    printf("\n=== TEST AVEC FICHIER INEXISTANT ===\n");
    char *error_line = get_next_line(-1);
    if (error_line == NULL)
        printf("✅ get_next_line(-1) retourne bien NULL\n");
    else
    {
        printf("❌ Erreur: get_next_line(-1) devrait retourner NULL\n");
        free(error_line);
    }

    printf("\n=== FIN DES TESTS ===\n");
    return (0);
}
