#include <stdio.h>
#include <string.h>

// TODO: Implémentez cette fonction
int ft_strlen(char *str)
{
	int i;

	// Votre code ici
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int main(void)
{
	char *str1;
	char str2[] = "World!";
	char str3[100] = "Test";

	str1 = "Hello";
	// TODO: Créez un programme qui :
	// 1. Utilisez strlen() pour obtenir la longueur de chaque chaîne
	// 2. Affichez les longueurs avec printf()
	// 3. Implémentez votre propre fonction ft_strlen() et comparez
	printf("%d\n", ft_strlen(str1));
	printf("%d\n", ft_strlen(str2));
	printf("%d\n", ft_strlen(str3));
	return (0);
}
