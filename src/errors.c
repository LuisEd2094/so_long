#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "../include/ft_printf.h"

void errors(int val)
{
    ft_printf("Error\n");
    if (val == 1)
        ft_printf("Usage: ./so_long path/to/file .\n");
    else if (val == 2)
        ft_printf("%s\n", strerror(errno));

    exit(EXIT_FAILURE);
        
} 