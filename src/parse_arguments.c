#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>



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

void    free_if_invalid(char *line, int fd, t_rect *rect_info, int error)
{
    free(line);
    BUFFER_SIZE = 0;
    get_next_line(fd);
    free(rect_info);
    close(fd);
    errors(error);
}

int check_char_with_current_infor(char chr, t_rect *rect_info)
{
    if (chr == '1' || chr == '0')
        return (1);
    else if(chr == 'P')
    {
        if (!rect_info->player)
        {
            rect_info->player = 1;
            rect_info->player_pos->x = rect_info->height;
            rect_info->player_pos->y = rect_info->current_line_width;
        }

        else
            return (0);
        return (1);
    }
    else if (chr == 'E')
    {
        if (!rect_info->exit)
            rect_info->exit = 1;
        else
            return (0);
        return (1);
    }
    else if (chr == 'C')
    {
        rect_info->collectables++;
        return (1);
    }
    return (1);
}

void    check_line(int  *is_EOF, char *line, t_rect *rect_info, int fd)
{
    int i = 0;

    if (line == NULL)
        check_if_EOF(is_EOF);
    else
    {
        while(line[i] && line[i] != '\n')
        {

            if(!check_if_valid_character(line[i]))
                free_if_invalid(line, fd, rect_info, 5);
            if(!check_char_with_current_infor(line[i], rect_info))
                free_if_invalid(line, fd, rect_info, 7);
            if (!rect_info->found_width && line[i] != '1')
                free_if_invalid(line, fd, rect_info, 6);
            else if((rect_info->current_line_width == 0 || (rect_info->current_line_width + 1) == rect_info->rect_width) && line[i] != '1' && rect_info->found_width)
                free_if_invalid(line, fd, rect_info, 6);
            if (rect_info->valid_if_last_line && line[i] != '1')
                rect_info->valid_if_last_line = 0;
            i++;
            rect_info->current_line_width++;
        }
        if (!rect_info->found_width && line[i] == '\n')
        {
            rect_info->rect_width = rect_info->current_line_width;
            rect_info->found_width = 1;
            rect_info->current_line_width = 0;
            rect_info->height++;
        }
        else if (line[i] == '\n' || !line[i])
        {
            if (rect_info->current_line_width != rect_info->rect_width)
                free_if_invalid(line, fd, rect_info, 3);
            if (line[i] == '\n') 
                rect_info->valid_if_last_line = 1;
            else if (!rect_info->valid_if_last_line)
                free_if_invalid(line, fd, rect_info, 6);
            rect_info->current_line_width = 0;
            rect_info->height++;
        }
            
    }
}

t_rect *init_rect_info(void)
{
    t_rect *new_rect;

    new_rect = (t_rect *)malloc(sizeof(t_rect));
    if (!new_rect)
        errors(2);
    new_rect->current_line_width = 0;
    new_rect->height = 0;
    new_rect->rect_width = 0;
    new_rect->found_width = 0;
    new_rect->valid_if_last_line = 1;
    new_rect->player = 0;
    new_rect->exit = 0;
    new_rect->collectables = 0;
    new_rect->player_pos = (t_position *)malloc(sizeof(t_position));
    new_rect->exit_pos = (t_position *)malloc(sizeof(t_position));
    return(new_rect);
}

void    parse_file(int fd)
{
    char *line;
    int is_EOF;
    t_rect *rect_info;

    rect_info = init_rect_info();
    is_EOF = 0;
    while (!is_EOF)
    {
        line = get_next_line(fd);
        check_line(&(is_EOF), line, rect_info, fd);
        free(line);
    }
    if (rect_info->height == rect_info->rect_width)
    {
        free(rect_info);
        errors(3);
    }
    if (!rect_info->player || !rect_info->exit || !rect_info->collectables)
        free_if_invalid(line, fd, rect_info, 7);

    /// Ill probably want to save some information from the rect_info to the full program
    /// haven't decided yet

    ft_printf("player x %d player y %d\n", rect_info->player_pos->x, rect_info->player_pos->y);
    free(rect_info->player_pos);
    free(rect_info->exit_pos);
    free(rect_info);
}

void    check_file_type(char *argv)
{
    size_t i;

    i = ft_strlen(argv);
    if (argv[i - 1] != 'r' || argv[i - 2] != 'e' || argv[i - 3] != 'b' || argv[i - 4] != '.')
        errors(4);
}


void    parse_arguments(int argc, char **argv)
{
    int fd;

    if (argc != 2)
        errors(1);
    check_file_type(argv[1]);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        errors(2);
    parse_file(fd);
    close(fd);    
}