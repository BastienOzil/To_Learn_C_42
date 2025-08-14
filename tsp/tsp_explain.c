#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <float.h> // ajouter cette bibliothèque pour FLT_MAX
// N'oubliez pas de compiler avec l'option -lm !

/* Cette approche pour résoudre le problème du voyageur de commerce 
utilise une stratégie de génération de permutations par force brute,
qui fonctionne assez bien avec une petite taille (N <= 11).
La fonction de backtracking récursive utilisée ici (generate_perms()) est structurée de manière similaire 
à celle utilisée dans ma solution à une autre question d'examen Rang 03 "permutations" 
(également dans mon repo). Je recommande de les étudier côte à côte.

Vous initialisez d'abord un tableau avec les indices des villes (0 à N-1). 
Ensuite, vous utilisez une fonction de backtracking récursive (variante de l'algorithme de Heap) 
pour générer systématiquement tous les ordres possibles (permutations) de ces indices de villes. 
Pour chaque permutation complète, vous calculez la longueur totale du trajet 
en additionnant les distances entre les villes consécutives et 
en ajoutant la distance de la dernière ville de retour à la première, 
mettant à jour une variable best_distance si un chemin plus court est trouvé.*/

// calcule la distance entre deux points
float    distance(float a[2], float b[2])
{
    return sqrtf((b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]));
}


/* VOS FONCTIONS COMMENCENT ICI */


// Calcule la distance totale d'un chemin donné (permutation des indices de villes).
// array: Le tableau principal des coordonnées des villes.
// perm: Un tableau représentant l'ordre des indices de villes pour le chemin actuel.
// size: Le nombre total de villes.
// Retourne la distance totale en tant que float.
float calc_total_distance(float (*array)[2], int *perm, int size)
{
	int city_index_current;
	int city_index_next;
	int i;
	float actual_distance = 0.0f;
	// Additionne les distances entre les villes consécutives dans la permutation.
	for (i = 0; i < size - 1; i++)
	{
		city_index_current = perm[i];
		city_index_next = perm[i + 1];
		actual_distance += distance(array[city_index_current], array[city_index_next]);
	}
	// Ajoute la distance de la dernière ville de retour à la première ville pour fermer la boucle.
	city_index_current = perm[i]; // i est maintenant (size - 1) depuis la boucle
	city_index_next = perm[0]; // Première ville dans la permutation
	actual_distance += distance(array[city_index_current], array[city_index_next]);
	return (actual_distance);
}	

// Fonction principale : utilise la méthode de backtracking standard pour générer les permutations
// Génère toutes les permutations de 'mutable_array' et calcule leurs longueurs de chemin.
// array: Le tableau principal des coordonnées des villes.
// mutable_array: Le tableau dont les éléments sont permutés (son contenu change pendant la récursion).
// size: Le nombre d'éléments dans le tableau/permutation.
// mutable_index_current: L'indice de départ pour l'étape actuelle de génération de permutation (profondeur actuelle).
// best_distance: Un pointeur vers une variable float qui stocke la distance minimale trouvée jusqu'à présent.
void generate_perms(float (*array)[2], int *mutable_array, int size,
					int mutable_index_current, float *best_distance)
{
	// Cas de base : Si mutable_index_current atteint size, 
	// une permutation complète a été formée.
	if (mutable_index_current == size)
	{
		float actual_distance = calc_total_distance(array, mutable_array, size);
		if (actual_distance < *best_distance)
			*best_distance = actual_distance;
		return ;
	}
	// Étape récursive : Itère de mutable_index_current à size-1 
	// pour choisir l'élément pour current_index.
	for (int i = mutable_index_current; i < size; i++)
	{
		// Échange les éléments pour créer un nouvel arrangement pour le niveau actuel.
		int temp = mutable_array[mutable_index_current];
		mutable_array[mutable_index_current] = mutable_array[i];
		mutable_array[i] = temp;
		// Récurse pour générer les permutations pour le reste du tableau (niveau suivant)
		generate_perms(array, mutable_array, size, mutable_index_current + 1,
						best_distance);
		// Backtrack : Échange de nouveau pour restaurer le tableau à son état avant l'appel récursif,
        // permettant à d'autres permutations d'être générées correctement pour le niveau actuel.
		temp = mutable_array[mutable_index_current];
		mutable_array[mutable_index_current] = mutable_array[i];
		mutable_array[i] = temp;
	}
}

// Fonction principale pour résoudre le problème du voyageur de commerce.
// (la fonction squelette a été fournie, vous devez remplir les blancs.)
// array: Un pointeur vers un tableau de coordonnées de villes (paires [x, y]).
// size: Le nombre de villes dans le tableau.
// Retourne la longueur du plus court chemin fermé possible visitant toutes les villes.
float tsp(float (*array)[2], ssize_t size)
{
    float best_distance;
    
	
	// ... VOTRE CODE COMMENCE ICI 


	best_distance = FLT_MAX; // initialise la meilleure distance à un très grand nombre 
	
	 // Gère les cas limites pour 0 ou 1 ville : la longueur du chemin est 0.
    if (size <= 1) {
        return 0.0f;
    }
	// Crée un tableau d'entiers allant de 0 à size - 1.
    // Ce tableau contiendra les indices des villes et sera permuté.
	int *mutable_array = malloc(sizeof(int) * size);
	if (!mutable_array)
		return FLT_MAX; // retourne un très grand nombre pour signifier une erreur
	
	for (int i = 0; i < size; i++)
		mutable_array[i] = i;

	// Génère les permutations et trouve la meilleure distance.
    // Optimisation : Commence à générer les permutations à partir de l'indice 1 (mutable_index_current = 1)
    // tout en fixant implicitement la ville à l'indice 0 dans mutable_array[0].
    // Cela réduit le nombre de permutations de N! à (N-1)! pour une boucle fermée.
	int mutable_index_start = 1;
	generate_perms(array, mutable_array, size, mutable_index_start, &best_distance);
	free(mutable_array);


	// ... VOTRE CODE SE TERMINE 


    return (best_distance);
}


/* VOS FONCTIONS SE TERMINENT ICI */


// Fonction pour déterminer le nombre de lignes (villes) dans un fichier.
// file: Un pointeur vers le flux FILE.
// Retourne le nombre de lignes, ou -1 en cas d'erreur.
ssize_t    file_size(FILE *file)
{
    char    *buffer = NULL;
    size_t    n = 0;
    ssize_t ret;

    errno = 0;
	// Lit les lignes une par une pour les compter.
    for (ret = 0; getline(&buffer, &n, file) != -1; ret++);

    free(buffer); // Libère le buffer alloué par getline
    if (errno || fseek(file, 0, SEEK_SET))
        return -1;
    return ret;
}

// Fonction pour lire les coordonnées des villes depuis un fichier dans un tableau.
// array: Un pointeur vers un tableau de float[2] où les coordonnées seront stockées.
// 		C'est un tableau 2D où chaque "ligne" a exactement 2 colonnes 
// 		(par ex., float coordinates[N][2]). 
// 		Chaque float[2] représente les coordonnées [x, y] d'une seule ville.
// file: Un pointeur vers le flux FILE à partir duquel lire.
// Retourne 0 en cas de succès, -1 en cas d'erreur.
int        retrieve_file(float (*array)[2], FILE *file)
{
    int tmp;
	// Parcourt le fichier, en lisant deux floats par ligne.
    for (size_t i = 0; (tmp = fscanf(file, "%f, %f\n", array[i] + 0, array[i] + 1)) != EOF; i++)
        if (tmp != 2) // Si fscanf n'a pas lu exactement deux floats, c'est une erreur.
        {
            errno = EINVAL;
            return -1;
        }
	// Vérifie toute autre erreur de lecture de fichier (par ex., erreur d'E/S).
    if (ferror(file))
        return -1;
    return 0;
}

int        main(int ac, char **av)
{
    char *filename = "stdin"; // L'entrée par défaut est l'entrée standard.
    FILE *file = stdin; // Le pointeur de fichier par défaut est stdin.
	// Si un nom de fichier est fourni comme argument de ligne de commande, ouvrir ce fichier.
    if (ac > 1)
    {
        filename = av[1];
        file = fopen(filename, "r");
    }
	// Vérifie si le fichier a été ouvert avec succès.
    if (!file)
    {
        fprintf(stderr, "Error opening %s: %m\n", filename);
        return 1;
    }
	// Détermine le nombre de villes (lignes) dans le fichier.
    ssize_t size = file_size(file);
    if (size == -1)
    {
        fprintf(stderr, "Error reading %s: %m\n", filename);
        fclose(file);
        return 1;
    }
	// Alloue de la mémoire pour le tableau pour stocker les coordonnées des villes.
    float (*array)[2] = calloc(size, sizeof (float [2]));
    if (!array)
    {
        fprintf(stderr, "Error: %m\n");
        fclose(file);
        return 1;
    }
	// Récupère les coordonnées des villes depuis le fichier dans le tableau.
    if (retrieve_file(array, file) == -1)
    {
        fprintf(stderr, "Error reading %s: %m\n", av[1]);
        fclose(file);
        free(array);
        return 1;
    }
	// Ferme le fichier s'il a été ouvert (c'est-à-dire, pas stdin).
    if (ac > 1)
        fclose(file);

    // Calcule et affiche la longueur du plus court chemin, formatée à deux décimales.
    printf("%.2f\n", tsp(array,	 size));
    free(array);
    return (0);
}

