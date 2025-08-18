// Créez un programme qui détecte si un motif existe dans une chaîne
// et affiche sa position

#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, int n) {
    // Votre fonction de l'exercice 4
}

int main(int ac, char **av) {
    if (ac != 3) return 1;
    
    char *text = av[1];      // "hello world"
    char *pattern = av[2];   // "world"
    
    // VOTRE CODE ICI
    // Parcourez 'text' caractère par caractère
    // À chaque position, vérifiez si 'pattern' commence ici
    // Utilisez ft_strncmp pour comparer
    // Affichez la position si trouvé
}