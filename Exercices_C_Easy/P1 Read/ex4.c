/*
 * Créez une fonction: char *get_next_line(int fd)
 * 
 * Cette fonction:
 * 1. Lit depuis le fd caractère par caractère
 * 2. S'arrête au '\n' ou EOF
 * 3. Retourne une ligne complète (avec le '\n')
 * 4. Retourne NULL à la fin du fichier
 * 
 * Vous DEVEZ utiliser malloc() pour allouer la ligne
 * 
 * Testez en lisant un fichier ligne par ligne:
 * while ((line = get_next_line(fd)) != NULL) {
 *     printf("%s", line);
 *     free(line);
 * }
 */