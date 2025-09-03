#include <stdio.h>
#include <stdlib.h>

int required_sum;
int size;
int *nums;

void print_subset(int subsize, int *subset)
{
	int i;

	i = 0;
	while (i < subsize)
	{
		printf("%d", subset[i]);
		if (i < subsize - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

int calcul_subset_sum(int subsize, int *subset)
{
	int actual_sum = 0;
	int i = 0;
	while (i < subsize)
	{
		actual_sum += subset[i];
		i++;
	}
	return actual_sum;
}

void solve(int subsize, int current_index, int *subset)
{
	if (current_index == size)
	{
		if (calcul_subset_sum(subsize, subset) == required_sum && subsize != 0)
			print_subset(subsize, subset);
		return;
	}
	solve(subsize, current_index + 1, subset);
	subset[subsize] = nums[current_index];
	solve(subsize + 1, current_index + 1, subset);
}

int main(int ac, char **av)
{
	int i;
	if (ac <= 2)
	{
		printf("\n");
		return 0;
	}
	required_sum = atoi(av[1]);
	size = ac - 2;
	nums = malloc(sizeof(int) * size);
	if (!nums)
		return 1;
	int *subset = calloc(size, sizeof(int));
	if (!subset)
	{
		free(nums);
		return 1;
	}
	i = 0;
	while (i < size)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}

	int subsize = 0;
	int current_index = 0;

	solve(subsize, current_index, subset);
	free(nums);
	free(subset);
}
