#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	buffer[9999];
	int		i;
	int		j;
	int		y;
	int		len;
	int		s_len;

	s_len = strlen(av[1]);

	if (ac != 2 || av[1] == NULL || s_len == 0)
		return (1);
	len = read(0, buffer, sizeof(buffer) - 1);
	if (len <= 0)
	{
		if (len < 0)
			write(1, "Error: \n", 8);
		return (1);
	}
	i = 0;
	while (i < len)
	{
		j = 0;
        while (j < s_len && i + j < len && buffer[i + j] == av[1][j])
            j++;
		if (j == s_len)
		{
			y = 0;
			while (y < s_len)
			{
				write(1, "*", 1);
				y++;
			}
			i += s_len;
		}
		else
		{
            write(1, &buffer[i], 1);
		    i++;
		}
	}
	return (0);
}