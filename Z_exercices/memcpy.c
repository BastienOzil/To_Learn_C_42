#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	source[] = "Hello World";
	char	*dest;
	int		len;

	dest = malloc(20);
	// TODO: Créez un programme qui :
	// 1. Utilisez memcpy() pour copier source vers dest
	// 2. Affichez dest
	// 3. Modifiez source et vérifiez que dest n'a pas changé
	// 4. Libérez la mémoire
	len = strlen(source);
	memcpy(dest, source, len);
	printf("%s\n", dest);
	source[0] = 'h';
	printf("%s\n", dest);
	free(dest);
	return (0);
}
