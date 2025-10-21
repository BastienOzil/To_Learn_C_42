/*
 * Créez un analyseur de fichier de log:
 * 
 * Format des logs: [2024-01-15 14:23:45] [ERROR] Message
 * 
 * Le programme doit:
 * 1. Lire un gros fichier de log (malloc)
 * 2. Parser chaque ligne
 * 3. Compter les occurrences par niveau:
 *    - INFO: 1250
 *    - WARN: 45
 *    - ERROR: 12
 * 4. Extraire tous les messages ERROR dans un nouveau fichier
 * 5. Calculer des statistiques temporelles
 * 
 * Utilisez:
 * - malloc/calloc pour les structures de données
 * - read pour lire le fichier
 * - write pour créer le rapport
 * - free pour tout nettoyer
 */