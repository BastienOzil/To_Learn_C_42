#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 2 || av[1] == NULL)
        return 1;

    int s_len = strlen(av[1]);
    if (s_len == 0)
        return 1;

    char *buffer = malloc(1024 * 1024);
    if (!buffer)
    {
        fprintf(stderr, "Error: ");
        perror("");
        return 1;
    }

    int total_len = 0;
    int len;
    
    while ((len = read(0, buffer + total_len, 1024 * 1024 - 1 - total_len)) > 0)
    {
        total_len += len;
        if (total_len >= 1024 * 1024 - 1)
            break;
    }
    
    if (len < 0)
    {
        fprintf(stderr, "Error: ");
        perror("");
        free(buffer);
        return 1;
    }

    int i = 0;
    int j, y;
    
    while (i < total_len)
    {
        j = 0;
        while (j < s_len && i + j < total_len && buffer[i + j] == av[1][j])
            j++;
        
        if (j == s_len)
        {
            y = 0;
            while (y < s_len)
            {
                if (write(1, "*", 1) < 0)
                {
                    fprintf(stderr, "Error: ");
                    perror("");
                    free(buffer);
                    return 1;
                }
                y++;
            }
            i += s_len;
        }
        else 
        {
            if (write(1, &buffer[i], 1) < 0)
            {
                fprintf(stderr, "Error: ");
                perror("");
                free(buffer);
                return 1;
            }
            i++;
        }
    }
    
    free(buffer);
    return 0;
}