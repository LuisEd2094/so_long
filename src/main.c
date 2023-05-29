#include "so_long.h"
#include "ft_printf.h"
#include <stdlib.h>

int BUFFER_SIZE = 1024;

int main(int argc, char **argv)
{
    parse_arguments(argc, argv);
    ft_printf("Valid Map\n");

    exit(EXIT_SUCCESS);
}