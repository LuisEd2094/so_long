#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int add_pos_to_list(t_pos_list *list, int x, int y)
{
    t_position  *new_pos;
    t_list      *node;

    new_pos = NULL;
    node = NULL;
    new_pos = (t_position *)malloc(sizeof(t_position));
    new_pos->x = x;
    new_pos->y = y;
    node = ft_lstnew(new_pos);
    ///////NEED TO CHECK NULLS AND RETURNS

    ft_lstadd_front(&(list)->head, node);
    return (1);
}

int check_and_save_char(char chr, t_rect *rect_info)
{
    if (chr == '0')
        return (1);
    else if (chr == '1' && rect_info->height > 0 && rect_info->current_line_width > 0 && rect_info->current_line_width < rect_info->rect_width - 1)
    {
        if(add_pos_to_list(rect_info->obstacles_pos, rect_info->current_line_width, rect_info->height))
            return (1);
        return (0);
    }
    else if(chr == 'P')
    {
        if (!rect_info->player)
            set_position(&(rect_info->player),rect_info->player_pos, rect_info);
        else
            return (0);
        return (1);
    }
    else if (chr == 'E')
    {
        if (!rect_info->exit)
            set_position(&(rect_info->exit),rect_info->exit_pos, rect_info);
        else
            return (0);
        return (1);
    }
    else if (chr == 'C')
    {
        rect_info->collectables++;
        if(add_pos_to_list(rect_info->collectables_pos, rect_info->current_line_width, rect_info->height))
            return (1);
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
                free_if_invalid_line(line, fd, rect_info, 5);
            if(!check_and_save_char(line[i], rect_info))
                free_if_invalid_line(line, fd, rect_info, 7);
            if (!rect_info->found_width && line[i] != '1')
                free_if_invalid_line(line, fd, rect_info, 6);
            else if((rect_info->current_line_width == 0 || (rect_info->current_line_width + 1) == rect_info->rect_width) && line[i] != '1' && rect_info->found_width)
                free_if_invalid_line(line, fd, rect_info, 6);
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
                free_if_invalid_line(line, fd, rect_info, 3);
            if (line[i] == '\n') 
                rect_info->valid_if_last_line = 1;
            else if (!rect_info->valid_if_last_line)
                free_if_invalid_line(line, fd, rect_info, 6);
            rect_info->current_line_width = 0;
            rect_info->height++;
        }  
    }
}

void	print_list(t_pos_list *pos_list)
{
    t_list *current = pos_list->head;
    while (current != NULL)
    {
        t_position *pos = (t_position *)(current->content);
        printf("(%d, %d)\n", pos->x, pos->y);
        current = current->next;
    }
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
        free_rect(rect_info);
        errors(3);
    }
    if (!rect_info->player || !rect_info->exit || !rect_info->collectables)
        free_if_invalid_line(line, fd, rect_info, 7);

    /// Ill probably want to save some information from the rect_info to the full program
    /// haven't decided yet

    //ft_printf("Player found %d player x %d player y %d\n", rect_info->player, rect_info->player_pos->x, rect_info->player_pos->y);
    //ft_printf("Exit found %d Exit x %d Exit y %d\n", rect_info->exit, rect_info->exit_pos->x, rect_info->exit_pos->y);
    
    
    //print_list(rect_info->obstacles_pos);

    free_rect(rect_info);
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