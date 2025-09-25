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

void recursive(int current, int size, char *s, char **all, int *perms)
{
	if (current == size)
	{
		ft_strcpy(all[(*perms)], s);
		(*perms)++;
		return;
	}
	int i = current;
	while (i < size)
	{
		char temp = s[i];
		s[i] = s[current];
		s[current] = temp;
		recursive(current + 1, size, s, all, perms);
		temp = s[i];
		s[i] = s[current];
		s[current] = temp;
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

void sort_perms(char **all, int total)
{
	int i = 0;
	int y;
	while (i < total)
	{
		y = i + 1;
		while (y < total)
		{
			if (ft_strcmp(all[i], all[y]) > 0)
			{
				char *tmp = all[i];
				all[i] = all[y];
				all[y] = tmp;
			}
			y++;
		}
		i++;
	}
}

void put_all(char **all, int total)
{
	int i = 0;
	while (i < total)
	{
		puts(all[i]);
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
	int total = ft_factorial(size);
	char **all = malloc(sizeof(char *) * total);
	int i = 0;

	while (i < total)
	{
		all[i] = calloc(size + 1, sizeof(char));
		i++;
	}

	int perms = 0;
	int current = 0;
	recursive(current, size, s, all, &perms);
	sort_perms(all, total);
	put_all(all, total);
	return 0;
}
