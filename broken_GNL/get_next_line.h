#ifndef GET_NEXT_LINE_H // bonne definition de l'entête
# define GET_NEXT_LINE_H // bon appel

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);

#endif