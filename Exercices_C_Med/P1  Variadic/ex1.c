/*
 * Créez une fonction sum_all(int count, ...) qui:
 * 1. Prend un nombre variable d'entiers
 * 2. Retourne leur somme
 * 
 * Exemple:
 * sum_all(3, 10, 20, 30) → 60
 * sum_all(5, 1, 2, 3, 4, 5) → 15
 * 
 * Aide:
 * - va_start(args, count) initialise la liste
 * - va_arg(args, int) récupère chaque argument
 * - va_end(args) nettoie
 */

 #include <stdarg.h>
#include <stdio.h>

int sum_all(int count, ...)
{
    va_list args;
    int sum = 0;
    
    // Votre code ici
    
    return sum;
}

int main(void)
{
    printf("%d\n", sum_all(3, 10, 20, 30));
    printf("%d\n", sum_all(5, 1, 2, 3, 4, 5));
    return 0;
}