/*
 * Créez un programme qui:
 * 1. Prend le temps avant une opération
 * 2. Effectue un calcul intensif (boucle de 1 million d'itérations)
 * 3. Prend le temps après
 * 4. Affiche le temps écoulé en millisecondes et microsecondes
 * 
 * Aide:
 * struct timeval {
 *     time_t      tv_sec;   // secondes
 *     suseconds_t tv_usec;  // microsecondes
 * };
 */

#include <sys/time.h>
#include <stdio.h>

long get_time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int main(void)
{
    long start = get_time_ms();
    
    // Votre code à mesurer
    
    long end = get_time_ms();
    printf("Temps écoulé: %ld ms\n", end - start);
    return 0;
}