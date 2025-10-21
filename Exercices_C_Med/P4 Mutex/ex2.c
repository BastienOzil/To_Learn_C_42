/*
 * Corrigez l'exercice 4.1 avec un mutex:
 *
 * 1. Créez un mutex global: pthread_mutex_t mutex;
 * 2. Initialisez-le avec pthread_mutex_init()
 * 3. Protégez counter avec lock/unlock
 * 4. Détruisez le mutex à la fin
 *
 * Maintenant le résultat doit toujours être 4 000 000!
 *
 * Mesurez la différence de temps avec/sans mutex
 */

#include <pthread.h>
#include <stdio.h>

int				counter = 0;
pthread_mutex_t	mutex;

void	*increment(void *arg)
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		counter++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t threads[4];

	pthread_mutex_init(&mutex, NULL);

	for (int i = 0; i < 4; i++)
		pthread_create(&threads[i], NULL, increment, NULL);

	for (int i = 0; i < 4; i++)
		pthread_join(threads[i], NULL);

	pthread_mutex_destroy(&mutex);

	printf("Counter: %d\n", counter);
	return (0);
}