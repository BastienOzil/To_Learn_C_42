#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int abs(int n)
{
	if (n < 0)
		return -n;
	return n;
}

int safe(int *b, int r, int c)
{
	int i = 0;
	while (i < r)
	{
		if (b[i] == c || abs(b[i] - c) == abs(i - r))
			return 0;
		i++;
	}
	return 1;
}

void solve(int *b, int n, int r)
{
	if (r == n)
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
		if (safe(b, r, c))
		{
			b[r] = c;
			solve(b, n, r + 1);
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
	solve(b, n, 0);
	free(b);
	return 0;
}
