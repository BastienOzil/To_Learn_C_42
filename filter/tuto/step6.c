// Créez un programme qui lit tout stdin dans un buffer
// puis affiche le contenu du buffer

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    char *buffer;
    int i = 0;
    char c;
    ssize_t result;

    // VOTRE CODE ICI
    buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL)
    {
        printf("error");
        return (0);
    }
    while (i < BUFFER_SIZE - 1)
    {
        result = read(STDIN_FILENO, &c, 1);
        if (result == -1)
        {
            fprintf(stderr, "error\n");
            free(buffer);
            return (1);
        }
        if (result == 0)
            break;
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    write(STDOUT_FILENO, buffer, i);
    free(buffer);

    // Allouez la mémoire avec malloc()
    // Vérifiez que malloc() n'a pas échoué
    // Lisez caractère par caractère et stockez dans buffer
    // Vérifiez de ne pas dépasser BUFFER_SIZE
    // Ajoutez '\0' à la fin
    // Affichez le buffer avec write()
    // Libérez la mémoire avec free()
}