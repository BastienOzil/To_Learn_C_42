// Créez un programme qui lit tout stdin dans un buffer
// puis affiche le contenu du buffer

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char *buffer;
    int index = 0;
    char c;
    ssize_t result;
    
    // VOTRE CODE ICI
    // Allouez la mémoire avec malloc()
    // Vérifiez que malloc() n'a pas échoué
    // Lisez caractère par caractère et stockez dans buffer
    // Vérifiez de ne pas dépasser BUFFER_SIZE
    // Ajoutez '\0' à la fin
    // Affichez le buffer avec write()
    // Libérez la mémoire avec free()
}