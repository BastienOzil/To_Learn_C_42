/*
 * D'abord, créez le PROBLÈME:
 * 
 * Variable globale: int counter = 0;
 * 
 * Créez 4 threads qui chacun:
 * - Incrémente counter 1 000 000 fois
 * 
 * Attendez tous les threads
 * Affichez counter (devrait être 4 000 000)
 * 
 * Exécutez plusieurs fois. Observez que le résultat est faux!
 * C'est une RACE CONDITION.
 */