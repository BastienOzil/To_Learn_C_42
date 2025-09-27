#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_res(int *res, int len)
{
    int i = 0;

    while (i < len)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", res[i]);
        i++;
    }
    printf("\n");
}

void recursive(int n, int count, int i, int num, int *s, int *res, int res_len)
{
    if (num == n && res_len > 0)
    {
        print_res(res, res_len);
        return;
    }

    if (i >= count || num > n)
        return;

    res[res_len] = s[i];
    recursive(n, count, i + 1, num + s[i], s, res, res_len + 1);

    recursive(n, count, i + 1, num, s, res, res_len);
}

int main(int ac, char **av)
{
    if (ac <= 2 || av[1] == NULL)
    {
        printf("\n");
        return 0;
    }

    int n = atoi(av[1]);
    int count = ac - 2;
    int *s = malloc(sizeof(int) * count);
    if (!s)
    {
        write(1, "\n", 1);
        return 0;
    }

    int *res = malloc(sizeof(int) * count);
    if (!res)
    {
        free(s);
        write(1, "\n", 1);
        return 0;
    }

    int i = 0;

    while (i < count)
    {
        s[i] = atoi(av[i + 2]);
        i++;
    }

    recursive(n, count, 0, 0, s, res, 0);

    free(s);
    free(res);

    return 0;
}