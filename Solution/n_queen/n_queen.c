#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_res(int *board, int n)
{
	int i = 0;

	while (i < n)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < n - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int is_valid(int n)
{
	if (n < 0)
		return (-n);
	return n;
}

int is_safe(int *board, int n, int x, int y)
{
	int i = 0;

	while (i < y)
	{
		if (board[i] == x)
			return 0;
		if (is_valid(board[i] - x) == is_valid(i - y))
			return 0;
		i++;
	}
	return 1;
}

void recursive(int *board, int n, int y)
{
	int x = 0;

	if (y == n)
	{
		print_res(board, n);
		return;
	}
	while (x < n)
	{
		if (is_safe(board, n, x, y))
		{
			board[y] = x;
			recursive(board, n, y + 1);
		}
		x++;
	}
}

int main(int ac, char **av)
{
	int *board;
	int n;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	n = atoi(av[1]);
	if (n <= 3)
	{
		write(1, "0\n", 2);
		return 0;
	}
	board = malloc(sizeof(int) * n);
	if (!board)
		return 1;
	recursive(board, n, 0);
	free(board);
	return 0;
}
