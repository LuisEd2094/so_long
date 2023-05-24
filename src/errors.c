#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "../include/ft_printf.h"

void errors(int val)
{
    if (val == 1)
        ft_printf("Error\nIncorrect number of arguments, please provide a single .ber file.\n");
    else if (val == 2)
        ft_printf("Error\n%s\n", strerror(errno));
    exit(1);
        
} 