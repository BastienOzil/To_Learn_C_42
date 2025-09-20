#include "get_next_line.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    if (s[i] == c)
    {
        return ((char *)(s + i));
    }
    else
        return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;

    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return (dest);
}

size_t ft_strlen(char *s)
{
    size_t ret;

    if (!s)
        return (0);
    ret = 0;
    while (*s)
    {
        ret++;
        s++;
    }
    return (ret);
}

int str_append_mem(char **s1, const char *s2, size_t size2)
{
    size_t size1 = 0;
    char *tmp;

    if (!s1 || !s2)
        return (0);

    if (*s1)
        size1 = ft_strlen(*s1);

    tmp = malloc(size1 + size2 + 1);
    if (!tmp)
        return (0);

    if (*s1)
    {
        ft_memcpy(tmp, *s1, size1);
        free(*s1);
    }

    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = '\0';
    *s1 = tmp;
    return (1);
}

int str_append_str(char **s1, char *s2)
{
    if (!s2)
        return (1);
    return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;

    if (!dest || !src || n == 0)
        return (dest);

    if (dest > src)
    {
        i = n;
        while (i > 0)
        {
            i--;
            ((char *)dest)[i] = ((char *)src)[i];
        }
    }
    else
    {
        i = 0;
        while (i < n)
        {
            ((char *)dest)[i] = ((char *)src)[i];
            i++;
        }
    }
    return (dest);
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret = NULL;
    char *tmp = ft_strchr(b, '\n');
    int read_ret;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    while (!tmp)
    {
        if (!str_append_str(&ret, b))
        {
            if (ret)
                free(ret);
            return (NULL);
        }

        read_ret = read(fd, b, BUFFER_SIZE);

        if (read_ret == -1)
        {
            if (ret)
                free(ret);
            return (NULL);
        }
        if (read_ret == 0)
        {
            b[0] = '\0';
            if (ret && ft_strlen(ret) > 0)
                return (ret);
            if (ret)
                free(ret);
            return (NULL);
        }
        b[read_ret] = '\0';
        tmp = ft_strchr(b, '\n');
    }

    if (!str_append_mem(&ret, b, tmp - b + 1))
    {
        if (ret)
            free(ret);
        return (NULL);
    }

    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
    return (ret);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("Erreur: impossible d'ouvrir le fichier de test\n");
        return (1);
    }

    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    write(1, "\n", 1);
    close(fd);
    return (0);
}
