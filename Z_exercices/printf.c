#include <stdio.h>

int	main(void)
{
	int nombre = 42;
	float pi = 3.14159;
	char *nom = "Aline";

	// TODO: Utilisez printf() pour afficher :
	// 1. Un entier avec %d
	// 2. Un float avec %f et %.2f
	// 3. Une chaîne avec %s
	// 4. Un caractère avec %c
	// 5. Un hexadécimal avec %x
	printf("%d\n", nombre);
	printf("%f\n", pi);
	printf("%2.f\n", pi);
	printf("%s\n", nom);
	printf("%c\n", nom[0]);
	printf("%x\n", nombre);

	return (0);
}