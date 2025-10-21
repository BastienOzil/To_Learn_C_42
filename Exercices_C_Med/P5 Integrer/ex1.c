/*
 * Créez une fonction de logging thread-safe:
 * 
 * void log_msg(const char *level, const char *format, ...)
 * 
 * Format: [2024-01-15 14:23:45.123] [INFO] [Thread-2] Message
 * 
 * Exigences:
 * - Utilisez va_start/va_arg pour les arguments variables
 * - Utilisez gettimeofday() pour le timestamp
 * - Utilisez un mutex pour synchroniser l'écriture
 * - Support pour: INFO, WARN, ERROR, DEBUG
 * 
 * Testez avec 5 threads qui loggent simultanément
 */