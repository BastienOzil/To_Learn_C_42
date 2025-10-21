/*
 * Créez la fonction: char *my_strdup(const char *str)
 * 
 * Cette fonction:
 * 1. Calcule la longueur de str
 * 2. Alloue strlen(str) + 1 octets
 * 3. Copie la chaîne
 * 4. Retourne le nouveau pointeur
 * 
 * Puis créez: char **my_split(char *str, char sep)
 * 
 * Cette fonction split une chaîne:
 * my_split("hello,world,42", ',') → ["hello", "world", "42", NULL]
 * 
 * Vous devez allouer:
 * - Le tableau de pointeurs
 * - Chaque sous-chaîne avec my_strdup
 * 
 * Créez aussi: void free_split(char **arr)
 */