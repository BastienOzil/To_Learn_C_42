#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	buffer[9999];
	int		i;
	int		y;
	int		len;

	if (ac != 2 || av[1] == NULL || av[1] == 0)
		return (1);
	len = read(0, buffer, sizeof(buffer) - 1);
	if (len <= 0)
		return (1);
	i = 0;
	while (i < len)
	{
		y = 0;
		while (buffer[i] == av[1][y])
		{
			i++;
			y++;
		}
		if (y == strlen(av[1]))
		{
			while (y > 0)
			{
				write(1, "*", 1);
				y--;
			}
		}
		else
		{
			i = i - y;
            write(1, &buffer[i], 1);
		    i++;
		}
	}
	return (0);
}
