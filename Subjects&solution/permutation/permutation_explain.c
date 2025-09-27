#include <unistd.h>
#include <stdlib.h>

int len(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

void swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void permute(char *s, int l, int r)
{
	if (l == r)
	{
		write(1, s, len(s));
		write(1, "\n", 1);
		return;
	}

	int i = l;
	while (i <= r)
	{
		swap(&s[l], &s[i]);
		permute(s, l + 1, r);
		swap(&s[l], &s[i]);
		i++;
	}
}

void sort_string(char *s)
{
	int n = len(s);
	int i = 0;
	int j;

	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
			j++;
		}
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
	int size = len(s);
	if (size == 0)
	{
		write(1, "\n", 1);
		return 0;
	}

	int i = 0;
	char *copy = malloc(size + 1);
	while (i <= size)
	{
		copy[i] = s[i];
		i++;
	}
	sort_string(copy);
	permute(copy, 0, size - 1);

	free(copy);
	return 0;
}
