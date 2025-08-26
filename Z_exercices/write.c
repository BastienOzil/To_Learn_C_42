#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    char *message1 = "Message normal\n";
    char *message2 = "Message d'erreur\n";
    
    // TODO: Créez un programme qui :
    // 1. Écrit message1 sur stdout avec write(STDOUT_FILENO, ...)
    // 2. Écrit message2 sur stderr avec write(STDERR_FILENO, ...)
    // 3. Vérifiez les valeurs de retour de write()
    write(STDOUT_FILENO, message1, strlen(message1));
    write(STDOUT_FILENO, message2, strlen(message2));
    
    return 0;
}