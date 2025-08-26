#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// TODO: Créez un programme qui :
	// 1. Alloue de la mémoire pour 3 entiers
	// 2. Remplissez avec 1, 2, 3
	// 3. Utilisez realloc() pour agrandir à 6 entiers
	// 4. Ajoutez 4, 5, 6 dans les nouveaux emplacements
	// 5. Affichez tout le tableau
	// 6. Libérez la mémoire
	int *array;
	int i = 0;
	array = malloc(3 * sizeof(int));
	if (!array)
		return (1);
	while (i < 3)
	{
		array[i] = i + 1;
		i++;
	}
    array = realloc(array, 6 * sizeof(int));
    if (!array)
        return (1);
    while (i < 6)
    {
        array[i] = i + 1;
        i++;
    }
    i = 0;
    while (i < 6)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
    free(array);
    return (0);
}