#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    float nombres[] = {16.0f, -5.5f, 25.0f, -10.2f};
    int i;

    // TODO: Pour chaque nombre :
    // 1. Affichez le nombre original
    // 2. Affichez sa valeur absolue avec fabsf()
    // 3. Si positif, affichez sa racine carrée avec sqrtf()

    while (i < sizeof(nombres))
    {
        printf("Nombre %d :\n", i + 1);
        printf("  Valeur originale : %.2f\n", nombres[i]);
        printf("  Valeur absolue   : %.2f\n", fabsf(nombres[i]));
        if (nombres[i] > 0)
        {
            printf("  Racine carrée    : %.2f\n", sqrtf(nombres[i]));
        }
        else
        {
            printf("  Racine carrée    : non calculée (nombre négatif)\n");
        }

        printf("\n");
        i++;
    }
    // N'oubliez pas de compiler avec -lm pour les fonctions math

    return 0;
}