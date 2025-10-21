/*
 * Créez un shell interactif qui:
 * 1. Lit une commande avec readline
 * 2. Si la commande commence par '!', remplace par la dernière commande
 * 3. Utilise rl_replace_line() pour modifier la ligne
 * 4. Utilise rl_redisplay() pour afficher la modification
 * 5. Exécute la commande
 */