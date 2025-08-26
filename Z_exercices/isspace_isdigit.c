#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char texte[] = "Hello 123 World!\n\t";
	int i = 0;

	// TODO: Créez un programme qui :
	// 1. Parcourt chaque caractère de texte
	// 2. Utilisez isspace() pour détecter les espaces
	// 3. Utilisez isdigit() pour détecter les chiffres
	// 4. Classifiez et affichez chaque caractère
	while (texte[i] != '\0')
	{
		while (isspace(texte[i]))
			i++;
		while (isdigit(texte[i]))
			i++;
		if (texte[i] == '\0')
        {
            printf("%s", "\n");
            return (0);
        }
		printf("%c", texte[i]);
		i++;
	}
	return (0);
}