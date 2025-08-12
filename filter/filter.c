#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int	main(int argc, char **argv)
{
	char *search_str;
	char *replacement;
	char *buffer;
	char *output_buffer;
	int search_len;
	int replacement_len;
	int bytes_read;
	int total_size = 0;
	int buffer_capacity = BUFFER_SIZE;
	char *found;
	int i;

	// Vérification des arguments
	if (argc != 2 || argv[1] == NULL || strlen(argv[1]) == 0)
	{
		return (1);
	}

	search_str = argv[1];
	search_len = strlen(search_str);

	// Créer la chaîne de remplacement (autant de '*' que la taille de search_str)
	replacement = malloc(search_len + 1);
	if (!replacement)
	{
		fprintf(stderr, "error malloc failed\n");
		return (1);
	}

	for (i = 0; i < search_len; i++)
	{
		replacement[i] = '*';
	}
	replacement[search_len] = '\0';
	replacement_len = search_len;

	// Allouer le buffer principal
	buffer = malloc(buffer_capacity);
	if (!buffer)
	{
		fprintf(stderr, "error malloc failed\n");
		free(replacement);
		return (1);
	}

	// Lire tout le contenu depuis stdin
	while ((bytes_read = read(STDIN_FILENO, buffer + total_size, buffer_capacity
				- total_size)) > 0)
	{
		total_size += bytes_read;

		// Agrandir le buffer si nécessaire
		if (total_size >= buffer_capacity - 1)
		{
			buffer_capacity *= 2;
			buffer = realloc(buffer, buffer_capacity);
			if (!buffer)
			{
				fprintf(stderr, "error realloc failed\n");
				free(replacement);
				return (1);
			}
		}
	}

	// Vérifier les erreurs de lecture
	if (bytes_read < 0)
	{
		fprintf(stderr, "error read failed\n");
		free(buffer);
		free(replacement);
		return (1);
	}

	// Terminer la chaîne
	buffer[total_size] = '\0';

	// Allouer un buffer de sortie (peut être plus grand à cause des remplacements)
	output_buffer = malloc(total_size * 2 + 1);
	if (!output_buffer)
	{
		fprintf(stderr, "error malloc failed\n");
		free(buffer);
		free(replacement);
		return (1);
	}

	// Effectuer le remplacement
	char *src = buffer;
	char *dst = output_buffer;

	while (*src)
	{
		found = strstr(src, search_str);

		if (found == src)
		{
			// Remplacer par les '*'
			memmove(dst, replacement, replacement_len);
			dst += replacement_len;
			src += search_len;
		}
		else if (found != NULL)
		{
			// Copier jusqu'à la prochaine occurrence
			int copy_len = found - src;
			memmove(dst, src, copy_len);
			dst += copy_len;
			src += copy_len;
		}
		else
		{
			// Copier le reste
			int remaining = strlen(src);
			memmove(dst, src, remaining);
			dst += remaining;
			break ;
		}
	}

	*dst = '\0';
	// Écrire le résultat
	printf("%s", output_buffer);
	free(buffer);
	free(replacement);
	free(output_buffer);

	return (0);
}
