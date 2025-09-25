#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	min_to_remove(char *s)
{
	int	open = 0;
	int close = 0;
	int i = 0;
	
	while(s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return (open + close);
}

void	recursive(int str, int total, int done, char *s)
{
	char	tmp;

	if (str == ft_strlen(s))
	{
		if (done == total && !min_to_remove(s))
			puts(s);
		return ;
	}
	if (done > total)
		return ;
	if (s[str] == '(' || s[str] == ')')
	{
		tmp = s[str];
		s[str] = ' ';
		recursive(str + 1, total, done + 1, s);
		s[str] = tmp;
		recursive(str + 1, total, done, s);
	}
	else
		recursive(str + 1, total, done, s);
}

int	main(int argc, char **argv)
{
	char	*s;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	s = argv[1];
	if (!min_to_remove(s))
	{
		puts(s);
		return (0);
	}
	recursive(0, min_to_remove(s), 0, s);
	return (0);
}
