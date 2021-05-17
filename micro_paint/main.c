#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

int main(int ac, char **av)
{
    FILE *file;
    char *draw;
    //t_zone zone;

    if (ac != 2)
        return (fail("Error: wrong argument\n"));
    if (!(file = fopen(av[1], "r")))
        return (fail("Error: Operation file corrupted\n"));
    
    printf("End\n");
    return (1);
}