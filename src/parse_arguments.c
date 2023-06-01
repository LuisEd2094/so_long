#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>



t_prg *parse_file(int fd)
{
    char *line;
    int is_EOF;
    t_prg *prg;

    prg = init_prg_info();
    is_EOF = 0;
    while (!is_EOF)
    {
        line = get_next_line(fd);
        check_line(&(is_EOF), line, prg, fd);
        free(line);
    }
    if (prg->height == prg->width)
    {
        free_prg(prg, 1);
        errors(3);
    }
    if (!prg->player || !prg->exit || !prg->collectables)
        free_if_invalid_line(line, fd, prg, 7);
    get_obstacles_and_collectables_to_arrays(prg);
    close(fd);   
    return (prg);
}

t_prg   *parse_arguments(int argc, char **argv)
{
    int fd;

    if (argc != 2)
        errors(1);
    check_file_type(argv[1]);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        errors(2);
    return (parse_file(fd));
 
}