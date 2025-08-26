#include <stdio.h>

int	main(void)
{
	FILE *fichier;
	int c;

	// TODO: Créez un programme qui :
	// 1. Ouvre un fichier en lecture
	// 2. Dans une boucle, lit avec fgetc()
	// 3. Utilisez feof() pour détecter la fin
	// 4. Utilisez ferror() pour détecter les erreurs
	// 5. Affichez un message approprié selon le cas

	fichier = fopen("test.txt", "r");
	if (fichier == NULL)
	{
		perror("Erreur d'ouverture du fichier");
		return (1);
	}

	while ((c = fgetc(fichier)) != EOF)
	{
		putchar(c);
	}

	if (ferror(fichier))
	{
		perror("Erreur de lecture du fichier");
	}

	fclose(fichier);
	return (0);
}