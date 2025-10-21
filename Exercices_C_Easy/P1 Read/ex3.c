/*
 * Créez un programme cat simplifié:
 * 
 * Usage: ./mycat fichier.txt
 * 
 * 1. Ouvre le fichier avec open()
 * 2. Lit tout le contenu par blocs de 4096 octets
 * 3. Affiche sur stdout avec write()
 * 4. Ferme le fichier
 * 5. Gère les erreurs (fichier inexistant, etc.)
 * 
 * Testez:
 * - ./mycat fichier.txt
 * - ./mycat fichier_inexistant.txt (doit afficher une erreur)
 */