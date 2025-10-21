/*
 * Créez un outil de benchmark pour comparer:
 * - Calcul séquentiel vs parallèle
 * 
 * Tâche: Calculer si N nombres sont premiers (N = 100 000)
 * 
 * 1. Version séquentielle: 1 thread
 * 2. Version parallèle: 2, 4, 8 threads
 * 
 * Pour chaque version:
 * - Mesurez le temps avec gettimeofday()
 * - Affichez: "X threads: Y ms (speedup: Zx)"
 * - Utilisez mutex pour compter les nombres premiers trouvés
 * 
 * Créez un rapport formaté avec des arguments variadiques:
 * print_benchmark_result(int threads, long time_ms, double speedup, ...)
 */