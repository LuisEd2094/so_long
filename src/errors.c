#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

void errors(int val)
{
    ft_printf("Error\n");
    if (val == 1)
        ft_printf("Usage: ./so_long path/to/file\n");
    else if (val == 2)
        perror(NULL);
    else if (val == 3)
        ft_printf("Please provide a rectangular map\n");
    else if (val == 4)
        ft_printf("Please provide a .ber file\n");
    else if (val == 5)
        ft_printf("Provide a map with just 1 0 E P C characters\n");
    else if (val == 6)
        ft_printf("Provide a map with a complete border made of obstacles\n");
    else if (val == 7)
        ft_printf("Must have at least 1 collectable and 1 player and 1 exit\n");
    else if (val == 8)
        ft_printf("Current map does not have a valid path\n");
    else if (val == 9)
        ft_printf("Max map size is 20 x 12\n");
    exit(EXIT_FAILURE);
} 