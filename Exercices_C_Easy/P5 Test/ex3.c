/*
 * Créez un mini-éditeur en ligne de commande:
 * 
 * Usage: ./editor fichier.txt
 * 
 * Commandes:
 * - "r"      : affiche le fichier (read + write)
 * - "a text" : ajoute une ligne (append)
 * - "d N"    : supprime la ligne N
 * - "w"      : sauvegarde (write)
 * - "q"      : quitte
 * 
 * Structure interne:
 * - Charge le fichier en mémoire (malloc)
 * - Tableau de lignes (char **)
 * - Modifie en mémoire
 * - Écrit tout à la fin
 * 
 * Gérez la mémoire proprement!
 */