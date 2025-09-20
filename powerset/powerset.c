#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_result(int *res, int len)
{
	int i = 0;

	while (i < len)
	{
		if (i > 0)
			printf(" ");
		printf("%d", res[i]);
		i++;
	}
	printf("\n");
}

void recursive(int *s, int count, int n, int i, int *num, int num_len, int res)
{
	if (res == n && num_len > 0)
	{
		print_result(num, num_len);
		return;
	}

	if (i >= count || res > n)
		return;

	num[num_len] = s[i];
	recursive(s, count, n, i + 1, num, num_len + 1, res + s[i]);

	recursive(s, count, n, i + 1, num, num_len, res);
}

int main(int ac, char **av)
{
	int n;
	int *s;
	int *num;
	int count;
	int i;

	if (ac <= 2)
	{
		printf("\n");
		return 0;
	}

	n = atoi(av[1]);
	count = ac - 2;

	s = malloc(count * sizeof(int));
	if (s == NULL)
		return 1;

	num = malloc(count * sizeof(int));
	if (num == NULL)
	{
		free(s);
		return 1;
	}

	i = 0;
	while (i < count)
	{
		s[i] = atoi(av[i + 2]);
		i++;
	}

	recursive(s, count, n, 0, num, 0, 0);

	free(s);
	free(num);

	return 0;
}
