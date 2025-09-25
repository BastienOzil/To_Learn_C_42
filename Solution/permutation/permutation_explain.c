#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int ft_factorial(int size)
{
	if (size <= 1)
		return 1;
	return (size * ft_factorial(size - 1));
}

void ft_strcpy(char *dest, char *s)
{
	int i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

void generate_all_perms(int current_index, int size, char *s, char **all_perms, int *perms_row_index)
{
	if (current_index == size)
	{
		ft_strcpy(all_perms[(*perms_row_index)], s);
		(*perms_row_index)++;
		return;
	}
	int i = current_index;
	while (i < size)
	{
		char temp = s[i];
		s[i] = s[current_index];
		s[current_index] = temp;
		generate_all_perms(current_index + 1, size, s, all_perms, perms_row_index);
		temp = s[i];
		s[i] = s[current_index];
		s[current_index] = temp;
		i++;
	}
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return 0;
}

void sort_perms(char **all_perms, int total_perms)
{
	int i = 0;
	int y;
	while (i < total_perms)
	{
		y = i + 1;
		while (y < total_perms)
		{
			if (ft_strcmp(all_perms[i], all_perms[y]) > 0)
			{
				char *tmp = all_perms[i];
				all_perms[i] = all_perms[y];
				all_perms[y] = tmp;
			}
			y++;
		}
		i++;
	}
}

void print_perms(char **all_perms, int total_perms)
{
	int i = 0;
	while (i < total_perms)
	{
		puts(all_perms[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	char *s = av[1];
	int size = ft_strlen(s);
	if (size == 0)
	{
		write(1, "\n", 1);
		return 0;
	}
	int total_perms = ft_factorial(size);
	char **all_perms = malloc(sizeof(char *) * total_perms);
	int i = 0;

	while (i < total_perms)
	{
		all_perms[i] = calloc(size + 1, sizeof(char));
		i++;
	}

	int perms_row_index = 0;
	int current_index = 0;
	generate_all_perms(current_index, size, s, all_perms, &perms_row_index);
	sort_perms(all_perms, total_perms);
	print_perms(all_perms, total_perms);
	return 0;
}
