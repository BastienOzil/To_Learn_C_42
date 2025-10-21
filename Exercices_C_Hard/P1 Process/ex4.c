/*
 * Améliorez l'exercice précédent en utilisant sigaction():
 * - Utilisez un sigset_t pour bloquer tous les signaux sauf SIGUSR1
 * - Configurez SA_RESTART pour redémarrer les appels système
 * - Testez avec SIGINT (Ctrl+C) et SIGTERM
 */