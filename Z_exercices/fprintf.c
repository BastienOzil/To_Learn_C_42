#include <stdio.h>

int main() {
    int valeur = 100;
    
    // TODO: Créez un programme qui :
    // 1. Utilisez fprintf(stdout, ...) pour afficher une info normale
    // 2. Utilisez fprintf(stderr, ...) pour afficher un avertissement
    // 3. Testez la redirection : ./prog > fichier.txt
    fprintf(stdout, "Info: La valeur est %d\n", valeur);
    fprintf(stderr, "Avertissement: La valeur est élevée (%d)\n", valeur);

    return (0);
}