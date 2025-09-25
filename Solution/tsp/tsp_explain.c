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

float calc_total_distance(float (*array)[2], int *perm, int size)
{
    int city_index_current;
    int city_index_next;
    int i;
    float actual_distance = 0.0f;
    for (i = 0; i < size - 1; i++)
    {
        city_index_current = perm[i];
        city_index_next = perm[i + 1];
        actual_distance += distance(array[city_index_current], array[city_index_next]);
    }
    city_index_current = perm[i];
    city_index_next = perm[0];
    actual_distance += distance(array[city_index_current], array[city_index_next]);
    return (actual_distance);
}

void generate_perms(float (*array)[2], int *mutable_array, int size,
                    int mutable_index_current, float *best_distance)
{
    if (mutable_index_current == size)
    {
        float actual_distance = calc_total_distance(array, mutable_array, size);
        if (actual_distance < *best_distance)
            *best_distance = actual_distance;
        return;
    }
    int i = mutable_index_current;
    while (i < size)
    {
        int temp = mutable_array[mutable_index_current];
        mutable_array[mutable_index_current] = mutable_array[i];
        mutable_array[i] = temp;
        generate_perms(array, mutable_array, size, mutable_index_current + 1,
                       best_distance);
        temp = mutable_array[mutable_index_current];
        mutable_array[mutable_index_current] = mutable_array[i];
        mutable_array[i] = temp;
        i++;
    }
}

float tsp(float (*array)[2], ssize_t size)
{
    float best_distance;

    // ... VOTRE CODE COMMENCE ICI

    best_distance = FLT_MAX;

    if (size <= 1)
    {
        return 0.0f;
    }
    int *mutable_array = malloc(sizeof(int) * size);
    if (!mutable_array)
        return FLT_MAX;

    int i = 0;
    while (i < size)
    {
        mutable_array[i] = i;
        i++;
    }
    int starter = 1;
    generate_perms(array, mutable_array, size, starter, &best_distance);
    free(mutable_array);

    // ... VOTRE CODE SE TERMINE

    return (best_distance);
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
