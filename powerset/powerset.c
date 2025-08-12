#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	find_subsets(int *numbers, int count, int target, int *current_subset,
		int subset_size, int start_index, int current_sum)
{
	int	i;

	if (current_sum == target)
	{
		i = 0;
		while (i < subset_size)
		{
			if (i > 0)
				printf(" ");
			printf("%d", current_subset[i]);
			i++;
		}
		printf("\n");
		return ;
	}
	if (current_sum > target || start_index >= count)
		return ;
	i = start_index;
	while (i < count)
	{
		current_subset[subset_size] = numbers[i];
		find_subsets(numbers, count, target, current_subset, subset_size + 1, i
			+ 1, current_sum + numbers[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	target;
	int	*numbers;
	int	*current_subset;
	int	count;
	int	i;

	if (argc < 2)
		return (0);
	target = atoi(argv[1]);
	count = argc - 2;
	if (count <= 0)
		return (0);
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		return (0);
	current_subset = malloc(sizeof(int) * count);
	if (!current_subset)
	{
		free(numbers);
		return (0);
	}
	i = 0;
	while (i < count)
	{
		numbers[i] = atoi(argv[i + 2]);
		i++;
	}
	find_subsets(numbers, count, target, current_subset, 0, 0, 0);
	free(numbers);
	free(current_subset);
	return (0);
}
