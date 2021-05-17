#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

typedef struct s_zone
{
    int height;
    int width;
    char background;
}               t_zone;

typedef struct s_list
{
    char type;
    float x;
    float y;
    float radius;
    char color;
}               t_list;

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

int free_all(FILE *file, char *str)
{
    fclose(file);
    if (str)
        free(str);
    return (1);
}

////////////////////////////////////////////////////////////////////////

int check_zone(t_zone *zone)
{
    return ((zone->width >= 0) && (zone->width <= 300) && (zone->height >= 0) && (zone->height <= 300))
}

char *get_zone(FILE *file, t_zone *zone)
{
    int count;
    char *array;
    int i = 0;

    if ((count = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
        return (NULL);
    if (count == -1)
        return (NULL);
    if (!(check_zone(zone)))
        return (NULL);
    array = (char *)malloc(sizeof(char) * (zone->width * zone->height))
    if (!array)
        return (NULL);
    while (i < zone->width * zone->height)
    {
        array[i] = zone->background;
        i++;
    }
    return (array);
}

///////////////////////////////////////////////////////////////////////

int main(int ac, char **av)
{
    FILE *file;
    char *draw;
    t_zone zone;

    if (ac != 2)
        return (fail("Error: arguments\n"));
    if (!(file = fopen(av[1], "r")))
        return (fail("Error: Operation file corrupted\n"));
    ///////////////////////////////////////////////////////
    if (!(draw = get_zone(file, &zone)))
        return (free_all(file, NULL) && fail("Error: Operation file corrupted\n"));
    //////////////////////////////////////////////////////
    if (!(drawing(file, draw, &zone)))
        return (free_all(file, draw) && fail("Error: Operation file corrupted\n"));
    ///////////////////////////////////////////////////////
    print_drawing(draw, &zone);
    free_all(file, draw);
    return (0);
}