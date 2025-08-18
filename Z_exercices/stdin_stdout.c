#include <unistd.h>
#include <stdio.h>

int main() {
    // stdin = entrée standard (clavier) = descripteur 0 = STDIN_FILENO
    // stdout = sortie standard (écran) = descripteur 1 = STDOUT_FILENO
    // stderr = erreur standard (écran) = descripteur 2 = STDERR_FILENO
    
    // TODO: Créez un programme qui :
    // 1. Lit 1 caractère depuis stdin avec read(STDIN_FILENO, &c, 1)
    // 2. Écrit ce caractère sur stdout avec write(STDOUT_FILENO, &c, 1)
    // 3. Répétez 5 fois
    
    char c;
    int i;
    
    for (i = 0; i < 5; i++) {
        // Votre code ici
    }
    
    return 0;
}