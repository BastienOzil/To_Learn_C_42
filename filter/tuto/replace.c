// Créez un programme qui remplace la PREMIÈRE occurrence d'un motif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av) {
    if (ac != 3) return 1;
    
    char *text = av[1];
    char *pattern = av[2];
    int pattern_len = strlen(pattern);
    int text_len = strlen(text);
    
    // VOTRE CODE ICI
    // Parcourez le texte
    // Quand vous trouvez le motif :
    //   - Écrivez des '*' avec write()
    //   - Sautez le motif
    // Sinon :
    //   - Écrivez le caractère actuel
}
