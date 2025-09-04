#include <stdio.h>

int main()
{
    char *messages[] = {
        "Premier message",
        "Deuxième message",
        "Dernier message",
        NULL};

    // TODO: Créez un programme qui :
    // 1. Utilisez puts() pour afficher chaque message
    // 2. Comparez avec printf()
    // 3. Observez que puts() ajoute automatiquement '\n'
    puts(messages[0]);
    puts(messages[1]);
    puts(messages[2]);
    printf("\n");
    printf("%s", messages[0]);
    printf("%s", messages[1]);
    printf("%s", messages[2]);
    printf("\n");

    return 0;
}