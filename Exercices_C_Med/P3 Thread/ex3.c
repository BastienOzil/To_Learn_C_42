/*
 * Créez 3 threads calculateurs:
 * - Thread 1: calcule la somme de 1 à 1000
 * - Thread 2: calcule la somme de 1001 à 2000
 * - Thread 3: calcule la somme de 2001 à 3000
 * 
 * Chaque thread retourne son résultat via pthread_join()
 * Le main affiche la somme totale
 * 
 * Utilisez malloc() pour allouer le résultat de chaque thread
 */