#include "so_long.h"
#include "get_next_line.h"
#include <errno.h>


void    set_position(int *value, t_position *position, t_rect *rect_info)
{
    *value += 1;
    position->y = rect_info->height;
    position->x = rect_info->current_line_width;
}

void    check_file_type(char *argv)
{
    size_t i;

    i = ft_strlen(argv);
    if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b' || argv[i - 4] != '.')
        errors(4);
}


void    free_if_invalid_line(char *line, int fd, t_rect *rect_info, int error)
{
    free(line);
    BUFFER_SIZE = 0;
    get_next_line(fd);
    free(rect_info->player_pos);
    free(rect_info->exit_pos);
    free(rect_info);
    close(fd);
    errors(error);
}

int    check_if_valid_character(char chr)
{
    char    *str;
    int     i;
    int     valid;

    str = "01CEP";
    i = 0;
    valid = 0;
    while(str[i])
    {
        if (str[i] == chr)
        {
            valid = 1;
            break;
        }
        i++;
    }
    return (valid);
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