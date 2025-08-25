// Créez un programme qui lit stdin caractère par caractère
// et affiche chaque caractère sur stdout

#include <unistd.h>
#include <stdio.h>

int main()
{
    char c;
    ssize_t result;

    // VOTRE CODE ICI
    
    while (1)
    {
        result = read(STDIN_FILENO, &c, 1);
        if (result == 0)
            return (0);
        if (result == -1)
            {
                perror("error");
                return(1);
            }
        write(STDOUT_FILENO, &c, 1);
    }

    // Utilisez read(STDIN_FILENO, &c, 1) dans une boucle
    // Utilisez write(STDOUT_FILENO, &c, 1) pour afficher
    // Gérez le cas où read() retourne -1 (erreur)
    // Gérez le cas où read() retourne 0 (fin de fichier)
    return (0);
}