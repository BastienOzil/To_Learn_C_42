/*
 * Créez 3 processus enfants qui:
 * - Affichent leur PID
 * - Dorment pendant (1, 2, 3) secondes respectivement
 * - Se terminent avec des codes différents (10, 20, 30)
 * 
 * Le parent doit:
 * - Attendre chaque enfant spécifiquement avec waitpid()
 * - Afficher le code de retour de chaque enfant
 */