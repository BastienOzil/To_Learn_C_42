/*
 * Créez une fonction avec timeout:
 * 
 * int read_with_timeout(int timeout_ms)
 * {
 *     // Attend une entrée utilisateur
 *     // Si rien après timeout_ms, retourne -1
 *     // Sinon retourne le caractère lu
 * }
 * 
 * Utilisez gettimeofday() pour vérifier le temps écoulé
 * Utilisez usleep() pour ne pas surcharger le CPU
 * Rendez stdin non-bloquant avec fcntl()
 */