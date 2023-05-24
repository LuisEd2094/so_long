#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "../include/so_long.h"
#include "../include/get_next_line.h"
#include <stdio.h>

void     check_if_EOF(int *is_EOF)
{
    if (errno == 0)
        *is_EOF = 1;
    else
        errors(2);
    
}

void    parse_file(int fd)
{
    char *line;
    int is_EOF;

    line = "";
    is_EOF = 0;
    //errno = ENOMEM;
    //errno = EIO;
    while (line != NULL || !is_EOF)
    {
        line = get_next_line(fd);
        //line = NULL; ERRORS AND LINE COMMENT AS REMINDER ON HOW TO TEST ERRORS
        if (line == NULL)
            check_if_EOF(&is_EOF);
        else
            printf("%s",line);
    }
    printf("\n");
}


void    parse_arguments(int argc, char **argv)
{
    int fd;

    if (argc == 1 || argc > 2)
        errors(1);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        errors(2);
    parse_file(fd);
    close(fd);    
}