#include "get_next_line_explain.h"

/*
 * ft_strchr - Recherche la première occurrence d'un caractère dans une chaîne
 *
 * Paramètres:
 * - s: la chaîne dans laquelle chercher
 * - c: le caractère à rechercher
 *
 * Retourne: un pointeur vers la première occurrence du caractère, ou NULL si non trouvé
 */
char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    // Parcourt la chaîne tant qu'on n'atteint pas la fin ET qu'on n'a pas trouvé le caractère
    while (s[i] && s[i] != c) // Fix bug #1: vérifier s[i] avant de comparer
        i++;                  // sinon cela crée une boucle infinie

    // Si on a trouvé le caractère (même si c'est '\0')
    if (s[i] == c)
    {
        return ((char *)(s + i)); // Retourne un pointeur vers cette position
    }
    else
        return (NULL); // Caractère non trouvé
}

/*
 * ft_memcpy - Copie n bytes de src vers dest
 *
 * Paramètres:
 * - dest: destination de la copie
 * - src: source de la copie
 * - n: nombre de bytes à copier
 *
 * Retourne: pointeur vers dest
 *
 * ATTENTION: Ne gère PAS les chevauchements mémoire (utiliser ft_memmove pour ça)
 */
void *ft_memcpy(void *dest, const void *src, size_t n) // Fix bug #2: retourner void*
// pour qu'une fonction void puisse return, elle doit etre pointé avec *
{
    size_t i = 0; // Fix bug #3: copier du début vers la fin
                  // il faut commencé la chaine à 0

    // Copie byte par byte de src vers dest
    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i]; // Cast en char* pour manipulation byte par byte
        i++;
    }
    return dest; // Retourne le pointeur de destination (convention standard)
}

/*
 * ft_strlen - Calcule la longueur d'une chaîne de caractères
 *
 * Paramètres:
 * - s: la chaîne dont on veut calculer la longueur
 *
 * Retourne: le nombre de caractères avant le '\0' terminal
 */
size_t ft_strlen(char *s)
{
    size_t ret;

    ret = 0;
    // Parcourt la chaîne jusqu'au caractère nul '\0'
    while (*s)
    {
        ret++; // Incrémente le compteur
        s++;   // Avance au caractère suivant
    }
    return (ret);
}

/*
 * str_append_mem - Concatène size2 caractères de s2 à la fin de s1
 *
 * Paramètres:
 * - s1: double pointeur vers la chaîne destination (sera modifiée)
 * - s2: chaîne source à ajouter
 * - size2: nombre de caractères de s2 à ajouter
 *
 * Retourne: 1 en cas de succès, 0 en cas d'erreur
 *
 * IMPORTANT: Cette fonction modifie s1 et libère l'ancienne mémoire
 */
int str_append_mem(char **s1, const char *s2, size_t size2) // Fix bug #4: double pointeur pour char *s1
{
    // Vérifications de sécurité
    if (!s1 || !*s1)
        return 0;

    size_t size1 = ft_strlen(*s1); // Calcule la taille actuelle de s1
    if (size1 == 0)                // Gérer le cas NULL, chaine a 0
        return 0;

    // Alloue une nouvelle zone mémoire assez grande pour contenir s1 + s2 + '\0'
    char *tmp = malloc(size1 + size2 + 1);
    if (!tmp)
        return (0); // Échec de l'allocation

    // Copie l'ancienne chaîne s1 dans la nouvelle zone
    if (*s1)
    {
        ft_memcpy(tmp, *s1, size1);
        free(*s1); // Libère l'ancienne mémoire
    }

    // Ajoute les size2 caractères de s2 après s1
    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = 0; // Ajoute le caractère nul terminal

    *s1 = tmp;  // Maintenant on peut modifier le pointeur original qu'as la fin
    return (1); // Succès
}

/*
 * str_append_str - Concatène entièrement s2 à la fin de s1
 *
 * Paramètres:
 * - s1: double pointeur vers la chaîne destination
 * - s2: chaîne source à ajouter entièrement
 *
 * Retourne: 1 en cas de succès, 0 en cas d'erreur
 *
 * Wrapper simple autour de str_append_mem
 */
int str_append_str(char **s1, char *s2)
{
    return (str_append_mem(s1, s2, ft_strlen(s2))); // Fix bug #5: passer s1 directement, pas besoin de tmp
}

/*
 * ft_memmove - Copie n bytes de src vers dest en gérant les chevauchements
 *
 * Paramètres:
 * - dest: destination de la copie
 * - src: source de la copie
 * - n: nombre de bytes à copier
 *
 * Retourne: pointeur vers dest
 *
 * Différence avec ft_memcpy: gère les chevauchements mémoire en adaptant le sens de copie
 */
void *ft_memmove(void *dest, const void *src, size_t n) // Retourner void*
// pour qu'une fonction void puisse return, elle doit etre pointé avec *, de même pour une variable void
{
    size_t i;

    // Si dest est après src dans la mémoire, risque de chevauchement
    if (dest > src)
    {
        // Copie de la fin vers le début pour éviter l'écrasement
        i = n;        // Fix bug #6: utiliser n au lieu de ft_strlen, fr_strlen ne sert a rien si on connait deja la longueur
        while (i > 0) // Éviter la boucle infinie avec unsigned
        {
            i--;
            ((char *)dest)[i] = ((char *)src)[i]; // Copie du dernier vers le premier
        }
    }
    else if (dest == src)
        return (dest); // Pas de copie nécessaire si même adresse
    else
    {
        // Copie normale du début vers la fin (pas de risque de chevauchement)
        i = 0;
        while (i < n)
        {
            ((char *)dest)[i] = ((char *)src)[i];
            i++;
        }
    }
    return (dest);
}

/*
 * get_next_line - Lit et retourne la prochaine ligne d'un fichier
 *
 * Paramètres:
 * - fd: descripteur de fichier à lire
 *
 * Retourne: la prochaine ligne (avec '\n' inclus), ou NULL si fin de fichier ou erreur
 *
 * PRINCIPE: Utilise un buffer statique pour conserver les données entre les appels.
 * À chaque appel, construit progressivement la ligne jusqu'à trouver un '\n'.
 */
char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = ""; // Buffer statique conservé entre les appels
    char *ret = NULL;                    // Chaîne de retour à construire
    char *tmp = ft_strchr(b, '\n');      // Cherche s'il y a déjà un '\n' dans le buffer

    // Vérifications de sécurité
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    // BOUCLE PRINCIPALE: tant qu'on n'a pas trouvé de '\n'
    while (!tmp)
    {
        // Ajoute le contenu actuel du buffer à la chaîne de retour
        if (!str_append_str(&ret, b))
            return (NULL); // Erreur d'allocation

        // Lit de nouvelles données du fichier
        int read_ret = read(fd, b, BUFFER_SIZE);

        // Gestion des erreurs de lecture
        if (read_ret == -1)
        {
            if (ret)
                free(ret);
            return (NULL);
        }
        // Gestion de la fin de fichier (EOF)
        if (read_ret == 0) // dans le cas EOF
        {
            // Si on a déjà lu des données, les retourner
            if (ret && ft_strlen(ret) > 0)
                return (ret);
            // Sinon, libérer et retourner NULL
            if (ret)
                free(ret);
            return (NULL);
        }

        b[read_ret] = '\0';       // Terminer le buffer par '\0'
        tmp = ft_strchr(b, '\n'); // Chercher '\n' dans le nouveau buffer
    }

    // ARRIVÉE ICI = on a trouvé un '\n' dans le buffer

    // Ajouter à ret tous les caractères jusqu'au '\n' inclus
    if (!str_append_mem(&ret, b, tmp - b + 1))
    {
        if (ret)
            free(ret);
        return (NULL);
    }

    // Sauvegarder le reste du buffer (après '\n') pour le prochain appel
    // tmp + 1 pointe sur le caractère après '\n'
    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);

    return (ret); // Retourner la ligne complète avec '\n'
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
