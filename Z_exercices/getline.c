#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char *ligne = NULL;
	size_t taille = 0;
	size_t longueur;

	// TODO: Créez un programme qui :
	// 1. Demande à l'utilisateur de taper une ligne
	// 2. Utilisez getline() pour la lire
	// 3. Affichez la ligne et sa longueur
	// 4. Libérez la mémoire

	printf("Tapez une ligne: ");
	// Votre code ici
	read(STDIN_FILENO, &ligne, taille);
	longueur = getline(&ligne, &taille, stdin);
	printf("read: %s", ligne);
	printf("Size: %zu\n", longueur);
	free(ligne);
	return (0);
}