#include <unistd.h>

int ft_strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return i;
}

int count_parenthesis(char *s)
{
    int open = 0;
    int close = 0;
    int i = 0;

    while (s[i])
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == ')')
        {
            if (open > 0)
                open--;
            else
                close++;
        }
        i++;
    }
    return (open + close);
}

void print_res(char *str)
{
    int i = 0;

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

void recursive(char *str, int len, int to_remove, int i, int done)
{
    char tmp;

    if (i == len)
    {
        if (done == to_remove && !count_parenthesis(str))
            print_res(str);
        return;
    }

    if (done > to_remove)
        return;

    if (str[i] == '(' || str[i] == ')')
    {
        tmp = str[i];
        str[i] = ' ';
        recursive(str, len, to_remove, i + 1, done + 1);
        str[i] = tmp;
        recursive(str, len, to_remove, i + 1, done);
    }
    else
        recursive(str, len, to_remove, i + 1, done);
}

int main(int ac, char **av)
{
    if (ac != 2 || av[1] == NULL)
        return 0;

    int len = ft_strlen(av[1]);
    if (len == 0)
        return 0;

    char *str = av[1];
    int to_remove = count_parenthesis(str);
    int i = 0;
    if (!count_parenthesis(str))
    {
        print_res(str);
        return 0;
    }
    recursive(str, len, to_remove, i, 0);

    return 0;
}
