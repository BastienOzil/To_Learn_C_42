#include <stdio.h>
#include <string.h>

int	main(void)
{
	char buffer[] = "Hello World";

	// TODO: Créez un programme qui :
	// 1. Affichez buffer initial
	// 2. Utilisez memmove() pour déplacer "World" au début
	//    memmove(buffer, buffer+6, 5);
	// 3. Affichez le résultat
	// 4. Testez avec memcpy() et observez la différence
	memmove(buffer, buffer + 6, 5);
	printf("%s\n", buffer);
	memcpy(buffer, buffer + 6, 5);
	printf("%s\n", buffer);

	return (0);
}