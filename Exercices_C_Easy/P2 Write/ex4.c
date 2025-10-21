/*
 * Créez un système de log:
 * 
 * void log_message(const char *level, const char *message)
 * 
 * Format: [2024-01-15 14:23:45] [INFO] Message ici\n
 * 
 * Exigences:
 * - Ouvre "app.log" en mode append (O_APPEND)
 * - Écrit avec write() uniquement
 * - Timestamp avec gettimeofday()
 * - Levels: INFO, WARN, ERROR, DEBUG
 * 
 * Testez en appelant log_message plusieurs fois
 * Le fichier doit contenir toutes les entrées
 */