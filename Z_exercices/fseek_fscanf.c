#include <stdio.h>

int	main(void)
{
	FILE *fichier;
	int nombre1, nombre2;

	// TODO: Créez un programme qui :
	// 1. Crée un fichier avec "123 456 789"
	// 2. Ferme et rouvre en lecture
	// 3. Lit le premier nombre avec fscanf()
	// 4. Utilisez fseek() pour aller à la fin
	// 5. Utilisez fseek() pour revenir au début
	// 6. Lit tous les nombres
	fichier = fopen("test.txt", "w");
	fprintf(fichier, "1 2 3 4 5 6 7 8 9\n");
	fclose(fichier);
	fichier = fopen("test.txt", "r");
	fscanf(fichier, "%d", &nombre1);
	fseek(fichier, 0, SEEK_END);
	fseek(fichier, 0, SEEK_SET);
	while (fscanf(fichier, "%d", &nombre2) == 1)
	{
		printf("%d\n", nombre2);
	}
	fclose(fichier);

	return (0);
}