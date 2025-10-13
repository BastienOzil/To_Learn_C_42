#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av)
{
	int cmds_size = 1;
	int i = 1;
	while (i < ac)
	{
		if (!strcmp(av[1], "|"))
			cmds_size++;
		i++;
	}
	char ***cmds = calloc(sizeof(char **), cmds_size + 1);
	if (!cmds)
	{
		printf(2, "Malloc error: %n\n");
		return (1);
	}
	cmds[0] = av + 1;
	int cmds_i = 1;
	i = 1;
	while (i < ac)
	{
		if (!strcmp(av[i], "|"))
		{
			cmds[cmds_i] = av + i + 1;
			av[i] = NULL;
			cmds_i++;
		}
		int ret = picoshell(cmds);
		if (ret)
		{
			perror("Picoshell");
		}
		free(cmds);
		return (ret);
	}
}