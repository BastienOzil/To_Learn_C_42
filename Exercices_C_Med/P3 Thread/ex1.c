/*
 * Créez un programme avec 2 threads:
 *
 * Thread 1 (main): Affiche "Main: 0", "Main: 1", ... "Main: 4"
 * Thread 2: Affiche "Thread: 0", "Thread: 1", ... "Thread: 4"
 *
 * Chaque thread dort 500ms entre les affichages (usleep)
 * Le main attend la fin du thread avec pthread_join()
 *
 * Observez l'entrelacement des affichages
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*thread_function(void *arg)
{
	for (int i = 0; i < 5; i++)
	{
		printf("Thread: %d\n", i);
		usleep(500000);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t thread;

	pthread_create(&thread, NULL, thread_function, NULL);

	for (int i = 0; i < 5; i++)
	{
		printf("Main: %d\n", i);
		usleep(500000);
	}

	pthread_join(thread, NULL);
	return (0);
}