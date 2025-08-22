// Créez un programme qui remplace la PREMIÈRE occurrence d'un motif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 3) return 1;
    
    char *text = av[1];
    char *pattern = av[2];
    int pattern_len = strlen(pattern);
    int text_len = strlen(text);
    // VOTRE CODE ICI
    int i = 0;
    int y = 0;
    while (i < text_len)
    {
        if (text[i] == pattern[y])
        {
            while (y < pattern_len && text[i] == pattern[y])
            {
                y++;
                i++;
            }
            i = i - y;
            if (y == pattern_len)
            {
                while (y > 0)
                {
                    write(1, "*", 1);
                    y--;
                    i++;
                }
                i = i - 1;
            }
            else
            {
                write(1, &text[i], 1);
                y = 0;
            }
        }
        else write(1, &text[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return 0;
    // Parcourez le texte
    // Quand vous trouvez le motif :
    //   - Écrivez des '*' avec write()
    //   - Sautez le motif
    // Sinon :
    //   - Écrivez le caractère actuel
}
