#include <stdio.h>  // Pour fprintf, perror
#include <string.h> // Pour strlen
#include <unistd.h> // Pour read, write, STDIN_FILENO, STDOUT_FILENO
#include <stdlib.h> // Pour malloc, free

// Définit la taille maximale du buffer. On ajoute +1 pour le caractère nul de fin,
// garantissant qu'on peut stocker jusqu'à 10k octets de contenu réel en sécurité.
#define MAX_INPUT_BUFFER_SIZE (10000 + 1)

// Fonction ft_strncmp personnalisée :
// Compare les 'n' premiers caractères de deux chaînes.
// Retourne 1 si tous les 'n' caractères correspondent, 0 sinon.
// Note : C'est une strncmp simplifiée qui vérifie seulement l'égalité,
// pas l'ordre lexicographique, ce qui est suffisant pour ce problème.
int ft_strncmp(char *s1, char *s2, int n)
{
    int i = 0;
    // Boucle tant que 'i' est dans les limites de 'n' et que les caractères s1[i] et s2[i] sont identiques.
    while (i < n && s1[i] == s2[i])
    {
        i++;
    }
    // Si 'i' a atteint 'n', cela signifie que tous les 'n' caractères correspondent.
    if (i == n)
    {
        return 1;
    }
    else
    {
        return 0; // Différence trouvée ou 'n' caractères pas atteints.
    }
}

int main(int ac, char **av)
{
    // --- 1. Gestion des arguments (GESTION D'ERREUR IMPORTANTE) ---
    // Le programme nécessite exactement un argument (argc == 2).
    // L'argument ne doit pas être NULL et sa longueur doit être supérieure à 0.
    if (ac != 2 || av[1] == NULL || strlen(av[1]) == 0)
    {
        return 1; // Retourne 1 comme spécifié pour un usage incorrect des arguments.
    }

    // --- 2. Allocation mémoire ---
    // Alloue un gros buffer pour stocker toute l'entrée depuis stdin.
    // MAX_INPUT_BUFFER_SIZE inclut l'espace pour le caractère nul de fin.
    char *buff = (char *)malloc(MAX_INPUT_BUFFER_SIZE);

    // --- Gestion d'erreur malloc (GESTION D'ERREUR IMPORTANTE) ---
    // Vérifie si malloc a échoué. Si elle retourne NULL, l'allocation mémoire a échoué.
    if (buff == NULL)
    {
        fprintf(stderr, "Error: "); // Affiche "Error: " sur l'erreur standard.
        perror("");                 // Affiche le message d'erreur du système (ex: "Cannot allocate memory").
        return 1;                   // Retourne 1 comme spécifié pour les erreurs malloc.
    }

    char *search_str = av[1];            // Pointeur vers la chaîne à rechercher (ex: "bonjour")
    char current_char;                   // Stockage temporaire pour un seul caractère lu depuis stdin
    ssize_t bytes_read_result;           // Stocke la valeur de retour de read() (nombre d'octets lus, 0 pour EOF, -1 pour erreur)
    int buff_idx = 0;                    // Index pour suivre la position actuelle dans 'buff' pendant la lecture
    int search_len = strlen(search_str); // Longueur de la chaîne à rechercher

    // --- 3. Première boucle : Lire toute l'entrée depuis stdin dans 'buff' ---
    // Lit un caractère à la fois jusqu'à EOF (bytes_read_result == 0),
    // qu'une erreur survienne (bytes_read_result == -1), ou que le buffer soit plein.
    while ((bytes_read_result = read(STDIN_FILENO, &current_char, 1)) > 0)
    {
        // Empêche le débordement de buffer : Arrête la lecture si on va dépasser l'espace alloué.
        // MAX_INPUT_BUFFER_SIZE - 1 garantit qu'on a toujours de la place pour le caractère nul de fin.
        if (buff_idx >= MAX_INPUT_BUFFER_SIZE - 1)
        {
            break; // Buffer plein, arrête de lire plus d'entrée.
        }
        buff[buff_idx++] = current_char; // Stocke le caractère dans 'buff' et incrémente l'index.
    }

    // --- Gestion d'erreur de lecture (IMPORTANT) ---
    // Après la boucle de lecture, vérifie si la dernière opération de lecture a résulté en erreur.
    if (bytes_read_result == -1)
    {
        fprintf(stderr, "error"); // Affiche "Error: " sur l'erreur standard.
        perror("");               // Affiche le message d'erreur du système.
        free(buff);               // Libère la mémoire allouée avant de quitter.
        return 1;                 // Retourne 1 comme spécifié pour les erreurs de lecture.
    }

    // --- Termine le buffer avec un caractère nul ---
    // Ceci est crucial pour les fonctions de chaînes comme ft_strncmp qui s'appuient sur les délimiteurs de chaînes.
    // 'buff_idx' contient maintenant le nombre total de caractères lus avec succès.
    buff[buff_idx] = '\0';

    // --- 4. Seconde boucle : Traite 'buff' et écrit vers stdout ---
    int process_idx = 0; // Index pour itérer à travers 'buff' pour le traitement et la sortie.
    while (buff[process_idx] != '\0')
    { // Boucle jusqu'à atteindre le caractère nul (fin de l'entrée valide).
        // Vérifie une correspondance de 'search_str' commençant à 'buff[process_idx]' :
        // 1. S'assure qu'il reste assez de caractères dans la partie *valide* de 'buff'
        //    pour une correspondance complète de 'search_str'. (process_idx + search_len <= buff_idx)
        // 2. Appelle ft_strncmp pour comparer la sous-chaîne avec 'search_str'.
        if (process_idx + search_len <= buff_idx &&
            ft_strncmp(&buff[process_idx], search_str, search_len) == 1)
        {
            // Si une correspondance est trouvée :
            // Écrit 'search_len' astérisques vers la sortie standard.
            int y = 0;
            while (y < search_len)
            {
                write(STDOUT_FILENO, "*", 1); // écrit un '*' à la fois.
                y++;
            }
            // Avance l'index de traitement au-delà de la chaîne correspondante.
            process_idx += search_len;
        }
        else
        {
            // Si aucune correspondance à la position actuelle :
            // Écrit le caractère actuel de 'buff' vers la sortie standard.
            write(STDOUT_FILENO, &buff[process_idx], 1); // écrit le caractère lui-même.
            // Avance l'index de traitement d'un caractère.
            process_idx++;
        }
    }

    // --- 5. Nettoyage mémoire ---
    free(buff); // Libère la mémoire allouée dynamiquement avant de quitter.

    return 0; // Programme exécuté avec succès.
}

/*
EXPLICATION DU PROGRAMME :

Ce programme implémente un filtre de texte qui :

1. PREND UN ARGUMENT : Une chaîne de caractères à rechercher dans le texte d'entrée

2. LIT L'ENTRÉE : Lit tout le texte depuis l'entrée standard (stdin) caractère par caractère

3. FILTRE LE TEXTE : Parcourt le texte lu et remplace chaque occurrence de la chaîne
   recherchée par des astérisques (autant d'astérisques que de caractères dans la chaîne)

4. ÉCRIT LA SORTIE : Affiche le texte modifié sur la sortie standard (stdout)

EXEMPLE D'UTILISATION :
./programme "hello"
Entrée : "Say hello to the world, hello again!"
Sortie : "Say ***** to the world, ***** again!"

GESTION D'ERREURS :
- Vérifie les arguments d'entrée
- Gère les erreurs d'allocation mémoire
- Gère les erreurs de lecture
- Évite les débordements de buffer

FONCTIONS UTILISÉES :
- malloc/free : Gestion mémoire dynamique
- read/write : E/S bas niveau
- strlen : Calcul de longueur de chaîne
- fprintf/perror : Gestion d'erreurs
*/