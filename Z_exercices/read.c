#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char buffer[10];
	ssize_t result;

	// TODO: Créez un programme qui :
	// 1. Lit jusqu'à 9 caractères avec read(STDIN_FILENO, buffer, 9)
	// 2. Vérifiez la valeur de retour :
	//    - Si > 0 : nombre d'octets lus
	//    - Si = 0 : fin de fichier (EOF)
	//    - Si < 0 : erreur
	// 3. Affichez le nombre d'octets lus
	// 4. Ajoutez '\0' et affichez le buffer avec printf()

	result = read(STDIN_FILENO, buffer, 9);
	if (result > 0)
	{
		buffer[result] = '\0';
		printf("Lus : %zd\n", result);
		printf("Contenu: %s\n", buffer);
	}
	else if (result == 0)
	{
		printf("EOF\n");
	}
	else
	{
		perror("Erreur");
	}
	return (0);
}