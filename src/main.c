#include "../include/so_long.h"

void    parse_arguments(int argc, char **argv)
{
    if (argc == 1 || argc > 2)
        exit(1);
    if (argv[0])
        return ;
}

int main(int argc, char **argv)
{
    parse_arguments(argc, argv);
}