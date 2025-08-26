#include <stdio.h>

int	main(void)
{
	FILE *fichier;
	int c;

	// TODO: Créez un programme qui :
	// 1. Crée un fichier avec fopen("test.txt", "w")
	// 2. Écrit "Hello\nWorld" avec fprintf()
	// 3. Ferme avec fclose()
	// 4. Rouvre en lecture avec fopen("test.txt", "r")
	// 5. Lit caractère par caractère avec fgetc()
	// 6. Affiche chaque caractère jusqu'à EOF
	fichier = fopen("test.txt", "w");
	fprintf(fichier, "Hello\nworld\n");
	fclose(fichier);
	fichier = fopen("test.txt", "r");
	c = 0;
	while ((c = fgetc(fichier)) != EOF)
	{
		putchar(c);
	}
	fclose(fichier);
	return (0);
}