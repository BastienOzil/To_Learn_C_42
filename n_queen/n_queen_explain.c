#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *board;
int board_size;

void print_solution(void)
{
	int i = 0;

	while (i < board_size)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < board_size - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return n;
}

int is_safe(int row, int col)
{
	int i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return 0;
		if (ft_abs(board[i] - row) == ft_abs(i - col))
			return 0;
		i++;
	}
	return 1;
}

void solve(int col)
{
	int row = 0;
	if (col == board_size)
	{
		print_solution();
		return;
	}
	while (row < board_size)
	{
		if (is_safe(row, col))
		{
			board[col] = row;
			solve(col + 1);
		}
		row++;
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
		write(1, "\n", 1);
		return 0;
	}
	board_size = n;
	board = malloc(sizeof(int) * board_size);
	if (!board)
		return 1;
	solve(0);
	free(board);
	return 0;
}
