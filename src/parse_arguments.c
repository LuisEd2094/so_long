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

int check_and_save_char(char chr, t_prg *prg)
{
    if (chr == '0')
        return (1);
    else if (chr == '1' && prg->height > 0 && prg->current_line_width > 0 && prg->current_line_width < prg->width - 1)
    {
        if(add_pos_to_list(prg->obstacles_pos, prg->current_line_width, prg->height))
            return (1);
        return (0);
    }
    else if(chr == 'P')
    {
        if (!prg->player)
            set_position(&(prg->player),prg->player_pos, prg);
        else
            return (0);
        return (1);
    }
    else if (chr == 'E')
    {
        if (!prg->exit)
            set_position(&(prg->exit),prg->exit_pos, prg);
        else
            return (0);
        return (1);
    }
    else if (chr == 'C')
    {
        prg->collectables++;
        if(add_pos_to_list(prg->collectables_pos, prg->current_line_width, prg->height))
            return (1);
        return (1);
    }
    return (1);
}


void    check_height_width(t_prg *prg)
{
    if (prg->height > prg->max_height || prg->width > prg->max_width)
    {
        free_prg(prg);
        errors(9);
    }
}


void    check_when_end_of_line(t_prg *prg, char *line, int i, int fd)
{
    if (!prg->found_width && line[i] == '\n')
    {
        prg->width = prg->current_line_width;
        prg->found_width = 1;
        prg->current_line_width = 0;
        prg->height++;
    }
    else if (line[i] == '\n' || !line[i])
    {
        if (prg->current_line_width != prg->width)
            free_if_invalid_line(line, fd, prg, 3);
        if (line[i] == '\n') 
            prg->valid_if_last_line = 1;
        else if (!prg->valid_if_last_line)
            free_if_invalid_line(line, fd, prg, 6);
        prg->current_line_width = 0;
        prg->height++;
    }
}
void    check_line(int  *is_EOF, char *line, t_prg *prg, int fd)
{
    int i = 0;

    if (line == NULL)
        check_if_EOF(is_EOF);
    else
    {
        while(line[i] && line[i] != '\n')
        {
            if(!check_if_valid_character(line[i]))
                free_if_invalid_line(line, fd, prg, 5);
            if(!check_and_save_char(line[i], prg))
                free_if_invalid_line(line, fd, prg, 7);
            if (!prg->found_width && line[i] != '1')
                free_if_invalid_line(line, fd, prg, 6);
            else if((prg->current_line_width == 0 || (prg->current_line_width + 1) == prg->width) && line[i] != '1' && prg->found_width)
                free_if_invalid_line(line, fd, prg, 6);
            if (prg->valid_if_last_line && line[i] != '1')
                prg->valid_if_last_line = 0;
            i++;
            prg->current_line_width++;
        }
        check_when_end_of_line(prg, line, i, fd);
        check_height_width(prg);  
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

void    get_internal_obst(t_prg *prg)
{
    t_list *current = prg->obstacles_pos->head;
    t_list *temp = current->next;
    t_position *pos = current->content;

    while (pos->y == prg->height - 1)
    {
        free(pos);
        free(current);
        current =  temp;
        temp = current->next;
        pos = current->content;
    }

    prg->obstacles_pos->head = current;

}

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
        free_prg(prg);
        errors(3);
    }
    if (!prg->player || !prg->exit || !prg->collectables)
        free_if_invalid_line(line, fd, prg, 7);

    /// Ill probably want to save some information from the prg to the full program
    /// haven't decided yet

    //ft_printf("Player found %d player x %d player y %d\n", prg->player, prg->player_pos->x, prg->player_pos->y);
    //ft_printf("Exit found %d Exit x %d Exit y %d\n", prg->exit, prg->exit_pos->x, prg->exit_pos->y);
    
    //print_list(prg->obstacles_pos);

    get_internal_obst(prg);
    //ft_printf("Nueva list\n");
   // print_list(prg->obstacles_pos);
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