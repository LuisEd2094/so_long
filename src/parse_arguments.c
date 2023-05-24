#include <fcntl.h>
#include <unistd.h>
#include "../include/so_long.h" 
#include <stdio.h>

void    parse_file(int fd)
{
    int     bytes;
    char    buffer[1024];

    bytes = 1;
    while(bytes)
    {
        bytes = read(fd, buffer, 1023);
        if (bytes < 0)
            errors(2);
        if (bytes)
        {
            printf("%s",buffer);
        }
    }

}

void    parse_arguments(int argc, char **argv)
{
    int fd;

    if (argc == 1 || argc > 2)
        errors(1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        errors(2);
    parse_file(fd);    
}