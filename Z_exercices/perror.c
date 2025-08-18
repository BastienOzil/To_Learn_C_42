#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    
    // TODO: Créez un programme qui :
    // 1. Essaie d'ouvrir un fichier inexistant avec open()
    // 2. Si ça échoue, utilisez perror() pour afficher l'erreur
    // 3. Comparez avec fprintf(stderr, ...)
    
    fd = open("fichier_inexistant.txt", O_RDONLY);
    if (fd == -1) {
        // Votre code ici
    }
    
    return 0;
}