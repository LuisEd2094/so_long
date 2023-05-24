#include <fcntl.h>
#include "../include/so_long.h" 

void    parse_arguments(int argc, char **argv)
{
    int fd;

    if (argc == 1 || argc > 2)
        errors(1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        errors(2);    
}