#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// TODO: Créez un programme qui :
	// 1. Alloue de la mémoire pour 10 entiers avec malloc()
	// 2. Vérifiez que l'allocation a réussi
	// 3. Remplissez le tableau avec les nombres 0 à 9
	// 4. Affichez le contenu
	// 5. Libérez la mémoire avec free()
	int *array;
	int i = 0;

	array = malloc(10 * sizeof(int));
	if (!array)
		return (1);
	while (i < 10)
	{
		array[i] = i;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
	free(array);

	return (0);
}