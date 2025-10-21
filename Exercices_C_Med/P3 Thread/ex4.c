/*
 * Créez un programme avec:
 * 
 * 1. Un thread détaché qui tourne en boucle infinie
 *    et affiche l'heure actuelle chaque seconde
 * 
 * 2. Le main qui fait autre chose (compte jusqu'à 10)
 *    puis se termine
 * 
 * Utilisez pthread_detach() pour que le thread ne nécessite
 * pas de pthread_join()
 * 
 * Question: que se passe-t-il quand main() se termine?
 */