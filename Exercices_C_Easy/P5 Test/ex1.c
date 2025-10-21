/*
 * Créez: char *read_file(const char *filename)
 * 
 * Cette fonction:
 * 1. Ouvre le fichier
 * 2. Détermine sa taille avec lseek() ou fstat()
 * 3. Alloue un buffer de cette taille + 1
 * 4. Lit tout le fichier dans le buffer
 * 5. Ajoute un '\0' à la fin
 * 6. Retourne le buffer
 * 
 * Dans le main:
 * - Lit un fichier
 * - Affiche son contenu
 * - Libère la mémoire
 * 
 * Testez avec des fichiers de différentes tailles
 */