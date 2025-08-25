#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    // TODO: Créez un programme qui :
    // 1. Alloue de la mémoire pour 5 entiers avec calloc()
    // 2. Affichez le contenu (devrait être des zéros)
    // 3. Modifiez quelques valeurs
    // 4. Affichez à nouveau
    // 5. Libérez la mémoire
    int *array;
    int i = 0;

    array = calloc(5, sizeof(int));
    if (!array)
        return (1);
    while(i < 5)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    array[0] = 10;
    array[1] = -15;
    array[2] = 20;
    array[4] = 30;
    array[3] = -25;

    i = 0;
    while(i < 5)
    {
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");

    free(array);
    return (0);
}