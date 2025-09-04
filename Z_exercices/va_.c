#include <stdio.h>
#include <stdarg.h>

// TODO: Implémentez cette fonction qui additionne n entiers
int somme(int n, ...)
{
    va_list args;
    int total = 0;
    int i;

    // 1. Initialisez avec va_start(args, n)
    // 2. Dans une boucle, récupérez chaque argument avec va_arg(args, int)
    // 3. Finalisez avec va_end(args)
    va_start(args, n);

    i = 0;
    while (i < n)
    {
        total += va_arg(args, int);
        i++;
    }

    va_end(args);

    return total;
}

int main()
{
    printf("Somme de 1,2,3: %d\n", somme(3, 1, 2, 3));
    printf("Somme de 10,20: %d\n", somme(2, 10, 20));
    return 0;
}