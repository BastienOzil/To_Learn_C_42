// Créez un programme qui détecte si un motif existe dans une chaîne
// et affiche sa position

#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, int n)
{
    int i = 0;
    while (s1[i] == s2[i] && i < n)
        i ++;
    if (i == n)
        return (1);
    else return (0);
} // votre fonction de compar.c

int main(int ac, char **av) {
    if (ac != 3) return 1;
    
    char *text = av[1];      // "hello world"
    char *pattern = av[2];   // "world"
    
    // VOTRE CODE ICI
    int i = 0;
    int text_len = strlen(text);
    int pattern_len = strlen(pattern);
    int pattern_start = 0;
    while (i <= text_len - pattern_len)
    {
        if(ft_strncmp(&text[i], pattern, pattern_len))
        {
            printf("Found %d\n", i);
            pattern_start = i;
        }
        i++;
    }
    if (pattern_start == 0)
        printf("Not found\n");
    // Parcourez 'text' caractère par caractère
    // À chaque position, vérifiez si 'pattern' commence ici
    // Utilisez ft_strncmp pour comparer
    // Affichez la position si trouvé
}