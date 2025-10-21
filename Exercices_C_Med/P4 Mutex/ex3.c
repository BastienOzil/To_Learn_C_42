/*
 * Buffer partagé: int buffer[10];
 * Index: int count = 0;
 * 
 * Thread producteur:
 * - Produit des nombres (1, 2, 3...)
 * - Les ajoute au buffer si count < 10
 * - Dort 100ms entre chaque production
 * 
 * Thread consommateur:
 * - Consomme (affiche) les nombres du buffer
 * - Si count > 0, prend le dernier élément
 * - Dort 150ms entre chaque consommation
 * 
 * Protégez buffer et count avec un mutex
 * Le producteur produit 20 éléments puis s'arrête
 */