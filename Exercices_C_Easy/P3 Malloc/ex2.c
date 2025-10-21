/*
 * Créez un tableau dynamique qui grandit:
 * 
 * 1. Commence avec une capacité de 4 éléments
 * 2. Lit des nombres jusqu'à EOF
 * 3. Quand le tableau est plein, double sa capacité:
 *    - Alloue un nouveau tableau 2x plus grand
 *    - Copie tous les éléments
 *    - Libère l'ancien tableau
 * 4. Affiche tous les nombres et la capacité finale
 * 
 * Testez avec:
 * seq 1 100 | ./prog
 * 
 * Affichez combien de fois le tableau a été redimensionné
 */