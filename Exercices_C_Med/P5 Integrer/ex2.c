/*
 * Créez un pool de 4 threads worker qui:
 * 
 * 1. Partagent une queue de tâches (tableau de 100 entiers)
 * 2. Chaque worker prend une tâche, calcule sa factorielle, l'affiche
 * 3. Utilisez un mutex pour synchroniser l'accès à la queue
 * 4. Utilisez un compteur pour savoir quand tout est terminé
 * 
 * Le main remplit la queue puis attend que tous les workers finissent
 * 
 * Mesurez le temps total avec gettimeofday()
 */