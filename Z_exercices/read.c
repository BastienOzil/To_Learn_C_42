#include <unistd.h>
#include <stdio.h>

int main() {
    char buffer[10];
    ssize_t result;
    
    // TODO: Créez un programme qui :
    // 1. Lit jusqu'à 9 caractères avec read(STDIN_FILENO, buffer, 9)
    // 2. Vérifiez la valeur de retour :
    //    - Si > 0 : nombre d'octets lus
    //    - Si = 0 : fin de fichier (EOF)
    //    - Si < 0 : erreur
    // 3. Affichez le nombre d'octets lus
    // 4. Ajoutez '\0' et affichez le buffer avec printf()
    
    return 0;
}