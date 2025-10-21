/*
 * Créez deux programmes identiques:
 * 
 * Programme A (avec malloc):
 * - Alloue un tableau de 10 entiers avec malloc
 * - Affiche le contenu (valeurs non initialisées = garbage)
 * 
 * Programme B (avec calloc):
 * - Alloue un tableau de 10 entiers avec calloc
 * - Affiche le contenu (tous à 0)
 * 
 * Observez la différence!
 * 
 * calloc(n, size) = malloc(n * size) + memset à 0
 */