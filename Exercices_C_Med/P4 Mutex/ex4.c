/*
 * Structure:
 * typedef struct {
 *     int balance;
 *     pthread_mutex_t mutex;
 * } BankAccount;
 * 
 * Créez 3 threads qui chacun:
 * - Fait 100 opérations aléatoires
 * - 50% chance de déposer 1-10€
 * - 50% chance de retirer 1-10€
 * - Affiche le solde après chaque opération
 * 
 * Le solde ne doit JAMAIS être négatif!
 * Utilisez le mutex pour protéger toutes les opérations
 * 
 * Balance initiale: 1000€
 */