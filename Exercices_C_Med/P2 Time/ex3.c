/*
 * Créez une barre de progression animée:
 * 
 * [##########----------] 50% (2.5s / 5.0s)
 * 
 * La barre se remplit en 5 secondes
 * Actualisez toutes les 100ms avec usleep(100000)
 * Utilisez \r pour réécrire sur la même ligne
 * 
 * Calculez le pourcentage basé sur gettimeofday()
 */