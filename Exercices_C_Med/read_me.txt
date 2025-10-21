Voici des exercices plus avance.
ici nous verrons les bases pour comprendre les projets:
ft_printf, Minitalk, Philosopher et l'exam03

Pour les threads:
gcc -Wall -Wextra -pthread fichier.c -o prog

Avec toutes les bibliothèques:
gcc -Wall -Wextra -pthread fichier.c -lreadline -o prog


Utilisation:

ERREUR: Toujours utiliser va_end
va_list args;
va_start(args, param);
return value; // Fuite mémoire!

CORRECT
va_list args;
va_start(args, param);
int result = va_arg(args, int);
va_end(args); // Toujours appeler va_end!
return result;

ERREUR: Passer l'adresse d'une variable locale
for (int i = 0; i < 5; i++)
    pthread_create(&threads[i], NULL, func, &i); // Tous verront la même valeur!

CORRECT: Allouer ou copier
for (int i = 0; i < 5; i++) {
    int *arg = malloc(sizeof(int));
    *arg = i;
    pthread_create(&threads[i], NULL, func, arg);
}

ERREUR: Oublier de déverrouiller
pthread_mutex_lock(&mutex);
if (error)
    return -1; // Mutex reste verrouillé!

CORRECT
pthread_mutex_lock(&mutex);
if (error) {
    pthread_mutex_unlock(&mutex);
    return -1;
}
pthread_mutex_unlock(&mutex);

Avec Valgrind:
valgrind --tool=helgrind ./prog  # Détecte les race conditions

Debeuguer les Threads avec:
gdb ./prog
(gdb) info threads              # Liste les threads
(gdb) thread 2                  # Bascule vers thread 2
(gdb) bt                        # Backtrace du thread courant