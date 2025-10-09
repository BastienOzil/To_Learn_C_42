#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <float.h>

float distance(float a[2], float b[2])
{
    return sqrtf((b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]));
}

float tsp(float (*array)[2], ssize_t size)
{
    float best_distance = 0.0f;
    // ... VOTRE CODE ICI

    if (size <= 0)
        return 0.0f;
    if (size == 1)
        return 0.0f;

    // Tableau pour marquer les villes visitées
    bool *visited = calloc(size, sizeof(bool));
    if (!visited)
        return -1.0f;

    // On commence à la ville 0
    ssize_t current = 0;
    visited[current] = true;
    ssize_t visited_count = 1;

    // Algorithme du plus proche voisin
    while (visited_count < size)
    {
        float min_dist = INFINITY;
        ssize_t nearest = -1;

        // Trouver la ville non visitée la plus proche
        ssize_t i = 0;
        while (i < size)
        {
            if (!visited[i])
            {
                float dist = distance(array[current], array[i]);
                if (dist < min_dist)
                {
                    min_dist = dist;
                    nearest = i;
                }
            }
            i++;
        }

        // Aller à la ville la plus proche
        if (nearest != -1)
        {
            best_distance += min_dist;
            current = nearest;
            visited[current] = true;
            visited_count++;
        }
    }

    // Retourner au point de départ
    best_distance += distance(array[current], array[0]);

    free(visited);
    return best_distance;
}

ssize_t file_size(FILE *file)
{
    char *buffer = NULL;
    size_t n = 0;
    ssize_t ret;

    errno = 0;
    ret = 0;
    while (getline(&buffer, &n, file) != -1)
        ret++;
    free(buffer);
    if (errno || fseek(file, 0, SEEK_SET))
        return -1;
    return ret;
}

int retrieve_file(float (*array)[2], FILE *file)
{
    int tmp;
    size_t i = 0;

    while ((tmp = fscanf(file, "%f, %f\n", array[i] + 0, array[i] + 1)) != EOF)
    {
        if (tmp != 2)
        {
            errno = EINVAL;
            return -1;
        }
        i++;
    }
    if (ferror(file))
        return -1;
    return 0;
}

int main(int ac, char **av)
{
    char *filename = "stdin";
    FILE *file = stdin;
    if (ac > 1)
    {
        filename = av[1];
        file = fopen(filename, "r");
    }
    if (!file)
    {
        fprintf(stderr, "Error opening %s: %m\n", filename);
        return 1;
    }
    ssize_t size = file_size(file);
    if (size == -1)
    {
        fprintf(stderr, "Error reading %s: %m\n", filename);
        fclose(file);
        return 1;
    }
    float (*array)[2] = calloc(size, sizeof(float[2]));
    if (!array)
    {
        fprintf(stderr, "Error: %m\n");
        fclose(file);
        return 1;
    }
    if (retrieve_file(array, file) == -1)
    {
        fprintf(stderr, "Error reading %s: %m\n", av[1]);
        fclose(file);
        free(array);
        return 1;
    }
    if (ac > 1)
        fclose(file);
    printf("%.2f\n", tsp(array, size));
    free(array);
    return (0);
}
