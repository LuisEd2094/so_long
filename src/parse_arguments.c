#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "so_long.h"
#include "get_next_line.h"
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


void    check_line(int  *is_EOF, char *line, t_rect *rect_info, int fd)
{
    int i = 0;

    if (line == NULL)
        check_if_EOF(is_EOF);
    else
    {
        while(line[i] && line[i] != '\n')
        {
            i++;
            rect_info->current_line_width++;
        }
        if (!rect_info->found_width && line[i] == '\n')
        {
            rect_info->rect_width = rect_info->current_line_width;
            rect_info->found_width = 1;
        }
        else if (line[i] == '\n' || !line[i])
        {
            if (rect_info->current_line_width != rect_info->rect_width)
            {   
                free(line);
                BUFFER_SIZE = 0;
                get_next_line(fd);
                free(rect_info);
                close(fd);
                errors(3);
            }

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

    printf("\n");
    free(rect_info);
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