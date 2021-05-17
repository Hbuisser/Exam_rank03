#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_zone
{
    int width;
    int height;
    char background;
}               t_zone;



int ft_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}

int fail(char *str)
{
    write(1, str, ft_strlen(str));
    return (1);
}

int free_all(FILE *file, char *draw)
{
    fclose(file);
    if (draw)
        free(draw);
    return (1);
}

int check_zone(t_zone *zone)
{
    return ((zone->width >= 0 && zone->width <= 300) && (zone->height >= 0 && zone->height <= 300))
}

char *get_zone(FILE *file, t_zone *zone)
{
    int count;
    char *array;
    int i = 0;

    if ((count = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
        return (NULL);
    if (count == (-1))
        return (NULL);
    if (!(check_zone(zone)))
        return (NULL);
}

int main(int ac, char **av)
{
    FILE *file;
    char *draw;
    t_zone zone;

    if (ac != 2)
        return (fail("Error: wrong argument\n"));
    if (!(file = fopen(av[1], "r")))
        return (fail("Error: Operation file corrupted\n"));
    if (!(draw = get_zone(file, &zone)))
        return (free_all(file, NULL) && fail("Error: Operation file corrupted\n")
    printf("End\n");
    return (1);
}