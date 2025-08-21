// Créez un programme qui :
// - Prend exactement 1 argument
// - Vérifie que l'argument n'est pas vide
// - Affiche l'argument ou retourne 1 en cas d'erreur

#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
    // VOTRE CODE ICI
    if (ac == 2)
    {
        if (av[1] == NULL || strlen(av[1]) == 0)
            return 1;
        printf("%s\n", av[1]);
    }
    else return 0;
    // Vérifier le nombre d'arguments
    // Vérifier que av[1] n'est pas NULL
    // Vérifier que av[1] n'est pas vide avec strlen()
    // Afficher l'argument ou retourner 1
}