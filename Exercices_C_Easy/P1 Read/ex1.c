/*
 * Créez un programme qui:
 * 1. Lit un caractère à la fois depuis stdin avec read()
 * 2. Affiche chaque caractère lu
 * 3. S'arrête à la fin du fichier (EOF)
 * 4. Compte le nombre total de caractères lus
 *
 * Testez avec:
 * - ./prog (entrée clavier, Ctrl+D pour EOF)
 * - echo "Hello" | ./prog
 * - ./prog < fichier.txt
 *
 * read() retourne:
 * - > 0 : nombre d'octets lus
 * - 0   : EOF (fin de fichier)
 * - -1  : erreur
 */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char buffer;
	ssize_t bytes_read;
	int count = 0;

	while ((bytes_read = read(0, &buffer, 1)) > 0)
	{
		write(1, &buffer, 1);
		count++;
	}

	printf("\nTotal: %d caractères\n", count);
	return (0);
}