#include "so_long.h"

int check_and_save_char(char chr, t_prg *prg)
{
    if (chr == '0')
        return (1);
    else if (chr == '1' && prg->height > 0 && prg->current_line_width > 0 && prg->current_line_width < prg->width - 1)
    {
        if(add_pos_to_list(prg->obstacles_list, prg->current_line_width, prg->height))
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
        if(add_pos_to_list(prg->collectables_list, prg->current_line_width, prg->height))
            return (1);
        return (1);
    }
    return (1);
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

int    check_while_line(char *line, int i, int fd, t_prg *prg)
{
    while(line[i] && line[i] != '\n')
    {
        if(!check_if_valid_character(line[i]))
            free_if_invalid_line(line, fd, prg, 5);
        if(!check_and_save_char(line[i], prg))
            free_if_invalid_line(line, fd, prg, 7);
        if (!prg->found_width && line[i] != '1')
            free_if_invalid_line(line, fd, prg, 6);
        else if((prg->current_line_width == 0 || \
        (prg->current_line_width + 1) == prg->width) && line[i] != '1' && prg->found_width)
            free_if_invalid_line(line, fd, prg, 6);
        if (prg->valid_if_last_line && line[i] != '1')
            prg->valid_if_last_line = 0;
        i++;
        prg->current_line_width++;
    }
    return (i);
}
void    check_line(int  *is_EOF, char *line, t_prg *prg, int fd)
{
    int i = 0;

    if (line == NULL)
        check_if_EOF(is_EOF);
    else
    {
        i = check_while_line(line, i, fd, prg);
        check_when_end_of_line(prg, line, i, fd);
        if (!check_height_width(prg))
            free_if_invalid_line(line, fd, prg, 9);
    }
}
