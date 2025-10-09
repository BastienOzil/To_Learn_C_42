#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putstr(char *str)
{
    int i = 0;

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_popen(const char *file, char *const argv[], char type)
{
    int pipefd[2];
    pid_t pid;

    if (file == NULL || argv == NULL || (type != 'r' && type != 'w'))
        return -1;

    if (pipe(pipefd) == -1)
        return -1;

    pid = fork();

    if (pid == -1)
    {
        close(pipefd[0]);
        close(pipefd[1]);
        return -1;
    }
    else if (pid == 0)
    {

        if (type == 'r')
        {
            close(pipefd[0]);
            dup2(pipefd[1], 1);
            close(pipefd[1]);
        }
        else
        {
            close(pipefd[1]);
            dup2(pipefd[0], 0);
            close(pipefd[0]);
        }

        execvp(file, argv);

        exit(1);
    }
    else
    {

        if (type == 'r')
        {
            close(pipefd[1]);
            return pipefd[0];
        }
        else
        {
            close(pipefd[0]);
            return pipefd[1];
        }
    }

    return -1;
}

// int main()
// {
//     int fd;
//     char *line;
//     fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
//     while ((line = get_next_line(fd)))
//         ft_putstr(line);
//     return (0);
// }

int main()
{
    int fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
    dup2(fd, 0);
    fd = ft_popen("grep", (char *const[]){"grep", "c", NULL}, 'r');
    char *line;
    while ((line = get_next_line(fd)))
        printf("%s", line);
}