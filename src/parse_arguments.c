#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "so_long.h"
#include "get_next_line.h"
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


int    check_character(char chr)
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

void    check_line(int  *is_EOF, char *line, t_rect *rect_info, int fd)
{
    int i = 0;

    if (line == NULL)
        check_if_EOF(is_EOF);
    else
    {
        while(line[i] && line[i] != '\n')
        {

            if(!check_character(line[i]))
                free_if_invalid(line, fd, rect_info, 5);
            if (!rect_info->found_width && line[i] != '1')
                free_if_invalid(line, fd, rect_info, 6);
            else if((rect_info->current_line_width == 0 || (rect_info->current_line_width + 1) == rect_info->rect_width) && line[i] != '1' && rect_info->found_width)
                free_if_invalid(line, fd, rect_info, 6);
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

    /// Ill probably want to save some information from the rect_info to the full program
    /// haven't decided yet 

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