#include "so_long.h"
#include "get_next_line.h"
#include <errno.h>


void    set_position(int *value, t_position *position, t_prg *prg)
{
    *value += 1;
    position->y = prg->height;
    position->x = prg->current_line_width;
}

void    check_file_type(char *argv)
{
    size_t i;

    i = ft_strlen(argv);
    if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b' || argv[i - 4] != '.')
        errors(4);
}

int    check_if_valid_character(char chr)
{
    char    *str;
    int     i;

    str = "01CEP";
    i = 0;
    while(str[i])
    {
        if (str[i] == chr)
            return (1);
        i++;
    }
    return (0);
}

void     check_if_EOF(int *is_EOF)
{
    //line = NULL; ERRORS AND LINE COMMENT AS REMINDER ON HOW TO TEST ERRORS
    //errno = ENOMEM;
    //errno = EIO;
    if (errno == 0)
        *is_EOF = 1;
    else
        errors(2);
}

int    check_height_width(t_prg *prg)
{
    if (prg->height > prg->max_height || prg->width > prg->max_width)
        return (0);
    return (1);
}
