/*
 * Créez un programme de copie de fichier:
 * 
 * Usage: ./mycopy source.txt destination.txt
 * 
 * 1. Ouvre le fichier source en lecture
 * 2. Crée/ouvre le fichier destination en écriture
 * 3. Lit par blocs de 4096 octets
 * 4. Écrit chaque bloc dans la destination
 * 5. Ferme les deux fichiers
 * 6. Gère toutes les erreurs possibles
 * 
 * Permissions du fichier créé: 0644 (rw-r--r--)
 * 
 * Testez:
 * - ./mycopy fichier.txt copie.txt
 * - diff fichier.txt copie.txt (doit être identique)
 */