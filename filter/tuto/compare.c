// Implémentez une fonction qui compare n caractères de deux chaînes

int ft_strncmp(char *s1, char *s2, int n) {
    // VOTRE CODE ICI
    // Comparez caractère par caractère
    // Retournez 1 si identique, 0 sinon
}

int main() {
    // Tests de votre fonction
    printf("%d\n", ft_strncmp("hello", "hello", 5)); // doit afficher 1
    printf("%d\n", ft_strncmp("hello", "world", 5)); // doit afficher 0
    printf("%d\n", ft_strncmp("abc", "abd", 2));     // doit afficher 1
    printf("%d\n", ft_strncmp("abc", "abd", 3));     // doit afficher 0
}