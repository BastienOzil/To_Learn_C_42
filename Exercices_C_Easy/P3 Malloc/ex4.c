/*
 * Créez une liste chaînée:
 * 
 * typedef struct s_node {
 *     int value;
 *     struct s_node *next;
 * } t_node;
 * 
 * Implémentez:
 * - t_node *create_node(int value)
 * - void list_add_back(t_node **head, int value)
 * - void list_print(t_node *head)
 * - void list_free(t_node *head)
 * 
 * Testez:
 * 1. Créez une liste avec 10 nombres
 * 2. Affichez la liste
 * 3. Libérez toute la mémoire
 * 4. Vérifiez avec valgrind --leak-check=full
 */