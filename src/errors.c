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
        ft_printf("Invalid map. Please provide a rectangular map\n");
    else if (val == 4)
        ft_printf("Invalid map file extension, please provide a .ber file\n");
    else if (val == 5)
        ft_printf("Invalid map, please provide a map with just 1 0 E P C characters\n");
    exit(EXIT_FAILURE);
} 