#include <stdio.h>
#include "../include/ft_printf.h"

void errors(int val)
{
    if (val == 1)
        ft_printf("Error\nIncorrect number of arguments, please provide a single .ber file.\n");
    exit(1);
        
} 