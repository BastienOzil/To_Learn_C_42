#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_solution(int *board, int size)
{
	int i = 0;

	while (i < size)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < size - 1)
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

int is_safe(int *board, int size, int row, int col)
{
	int i = 0;

	while (i < col)
	{
		if (board[i] == row)
			return 0;
		if (is_valid(board[i] - row) == is_valid(i - col))
			return 0;
		i++;
	}
	return 1;
}

void solve(int *board, int size, int col)
{
	int row = 0;

	if (col == size)
	{
		print_solution(board, size);
		return;
	}
	while (row < size)
	{
		if (is_safe(board, size, row, col))
		{
			board[col] = row;
			solve(board, size, col + 1);
		}
		row++;
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
	solve(board, n, 0);
	free(board);
	return 0;
}
