#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int abs(int n)
{
	if (n < 0)
		return -n;
	return n;
}

int safe(int *b, int x, int c)
{
	int i = 0;
	while (i < x)
	{
		if (b[i] == c || abs(b[i] - c) == abs(i - x))
			return 0;
		i++;
	}
	return 1;
}

void recursive(int *b, int n, int x)
{
	if (x == n)
	{
		int i = 0;
		while (i < n)
		{
			if (i > 0)
				fprintf(stdout, " ");
			fprintf(stdout, "%d", b[i]);
			i++;
		}
		fprintf(stdout, "\n");
		return;
	}
	int c = 0;
	while (c < n)
	{
		if (safe(b, x, c))
		{
			b[x] = c;
			recursive(b, n, x + 1);
		}
		c++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int n = atoi(av[1]);
	if (n <= 3)
	{
		write(1, "0\n", 2);
		return 0;
	}
	int *b = malloc(n * sizeof(int));
	recursive(b, n, 0);
	free(b);
	return 0;
}
