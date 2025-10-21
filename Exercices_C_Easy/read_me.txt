Voici des exercice qui vous aideront apres le libft 
pour les projets comme:
Get_next_line, Push_swap et l'exam02.

La Partie 5 est la pour vous tester

Read:
ERREUR: Ne pas vérifier la valeur de retour
char buffer[100];
read(fd, buffer, 100);
buffer[100] = '\0';
Peut dépasser!

CORRECT
char buffer[101];
ssize_t n = read(fd, buffer, 100);
if (n > 0)
    buffer[n] = '\0';

Write:
ERREUR: write peut écrire moins que demandé
write(fd, buffer, size);

CORRECT: Boucle jusqu'à tout écrire
size_t written = 0;
while (written < size) {
    ssize_t n = write(fd, buffer + written, size - written);
    if (n < 0) return -1;
    written += n;
}

Malloc:
ERREUR: Ne pas vérifier NULL
char *str = malloc(100);
strcpy(str, "hello");
Crash si malloc a échoué!

CORRECT
char *str = malloc(100);
if (!str) {
    perror("malloc");
    return NULL;
}
strcpy(str, "hello");

Free:
ERREUR: Double free
free(ptr);
free(ptr);
Crash!

CORRECT
free(ptr);
ptr = NULL;
Évite le double free

ERREUR: Use after free
free(ptr);
printf("%s\n", ptr);
Comportement indéfini!

CORRECT
free(ptr);
ptr = NULL;
if (ptr)
    printf("%s\n", ptr);

Calloc:
malloc: NON initialisé (rapide)
int *arr1 = malloc(10 * sizeof(int));
arr1 contient des valeurs aléatoires!

calloc: Initialisé à 0 (un peu plus lent)
int *arr2 = calloc(10, sizeof(int));
arr2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Si vous avez besoin de 0, utilisez calloc
Sinon, utilisez malloc (plus rapide)

Debogage:
Compilation
gcc -g -Wall -Wextra program.c -o program

Détection de fuites
valgrind --leak-check=full ./program

Détection d'erreurs mémoire
valgrind --track-origins=yes ./program

Avant de lancer le programme
ls -l /proc/$$/fd

Dans le programme, affichez getpid()
Puis pendant qu'il tourne:
ls -l /proc/PID/fd

Créer des fichiers de test
dd if=/dev/zero of=small.txt bs=1K count=1    1 KB
dd if=/dev/zero of=medium.txt bs=1M count=1   1 MB
dd if=/dev/zero of=large.txt bs=1M count=100  100 MB

Tester votre programme
./prog small.txt
./prog medium.txt
./prog large.txt