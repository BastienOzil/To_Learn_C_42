#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

float	distance(float a[2], float b[2])
{
	return (sqrtf((b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1]
				- a[1])));
}

float	tsp(float (*array)[2], ssize_t size)
{
	float	best_distance;
	int		*perm;
	bool	has_next;
	float	current_distance;
	int		i;
	int		j;
	int		tmp;
	int		left;
	int		right;

	if (size == 0)
		return (0.0f);
	if (size == 1)
		return (0.0f);
	perm = malloc(size * sizeof(int));
	if (!perm)
		return (-1.0f);
	i = 0;
	while (i < size)
	{
		perm[i] = i;
		i++;
	}
	best_distance = INFINITY;
	has_next = true;
	while (has_next)
	{
		current_distance = 0.0f;
		i = 0;
		while (i < size - 1)
		{
			current_distance += distance(array[perm[i]], array[perm[i + 1]]);
			i++;
		}
		if (current_distance < best_distance)
			best_distance = current_distance;
		i = size - 2;
		while (i >= 0 && perm[i] >= perm[i + 1])
			i--;
		if (i < 0)
		{
			has_next = false;
		}
		else
		{
			j = size - 1;
			while (perm[j] <= perm[i])
				j--;
			tmp = perm[i];
			perm[i] = perm[j];
			perm[j] = tmp;
			left = i + 1;
			right = size - 1;
			while (left < right)
			{
				tmp = perm[left];
				perm[left] = perm[right];
				perm[right] = tmp;
				left++;
				right--;
			}
		}
	}
	free(perm);
	return (best_distance);
}

ssize_t	file_size(FILE *file)
{
	char	*buffer;
	size_t	n;
	ssize_t	ret;

	buffer = NULL;
	n = 0;
	errno = 0;
	ret = 0;
	while (getline(&buffer, &n, file) != -1)
		ret++;
	free(buffer);
	if (errno || fseek(file, 0, SEEK_SET))
		return (-1);
	return (ret);
}

int	retrieve_file(float (*array)[2], FILE *file)
{
	int		tmp;
	size_t	i;

	i = 0;
	while ((tmp = fscanf(file, "%f, %f\n", array[i] + 0, array[i] + 1)) != EOF)
	{
		if (tmp != 2)
		{
			errno = EINVAL;
			return (-1);
		}
		i++;
	}
	if (ferror(file))
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	char	*filename;
	FILE	*file;
	ssize_t	size;

	filename = "stdin";
	file = stdin;
	if (ac > 1)
	{
		filename = av[1];
		file = fopen(filename, "r");
	}
	if (!file)
	{
		fprintf(stderr, "Error opening %s: %m\n", filename);
		return (1);
	}
	size = file_size(file);
	if (size == -1)
	{
		fprintf(stderr, "Error reading %s: %m\n", filename);
		fclose(file);
		return (1);
	}
	float(*array)[2] = calloc(size, sizeof(float[2]));
	if (!array)
	{
		fprintf(stderr, "Error: %m\n");
		fclose(file);
		return (1);
	}
	if (retrieve_file(array, file) == -1)
	{
		fprintf(stderr, "Error reading %s: %m\n", av[1]);
		fclose(file);
		free(array);
		return (1);
	}
	if (ac > 1)
		fclose(file);
	printf("%.2f\n", tsp(array, size));
	free(array);
	return (0);
}
