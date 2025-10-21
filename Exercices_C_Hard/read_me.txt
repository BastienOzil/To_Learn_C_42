Voici quelques exercices plus pousse en C.
Il vous faciliteront la comprehension sur les projet de 42 comme:
Minitalk, Minishell, Cube3D et l'exam04.

"Si tu reussi ici, tu reussira partout. Mais si tu ne reussie pas ici... bienvenu au club!" 

Compilez avec les warnings:
gcc -Wall -Wextra -Werror fichier.c -lreadline

Vérifiez toujours les valeurs de retour:
    if (fork() == -1) {
       perror("fork");
       exit(1);
   }

Utilisez man pour la documentation:
man 2 fork    # Appels système
man 3 printf  # Fonctions de bibliothèque

Testez avec valgrind:
valgrind --leak-check=full ./votre_programme
