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

void recursive(int n, int count, int i, int total, int *s, int *res, int res_len)
{
    if (i == count && total == n && res_len > 0)
    {
        print_res(res, res_len);
        return;
    }

    if (i >= count)
        return;

    res[res_len] = s[i];
    recursive(n, count, i + 1, total + s[i], s, res, res_len + 1);

    recursive(n, count, i + 1, total, s, res, res_len);
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
        return 0;

    int *res = malloc(sizeof(int) * count);
    if (!res)
    {
        free(s);
        return 0;
    }

    int i = 0;

    while (i < count)
    {
        s[i] = atoi(av[i + 2]);
        i++;
    }

    if (n == 0)
        printf("\n");

    recursive(n, count, 0, 0, s, res, 0);

    free(s);
    free(res);

    return 0;
}