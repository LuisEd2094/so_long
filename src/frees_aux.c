#include "so_long.h"
#include "get_next_line.h"


void free_prg(t_prg *prg)
{
    free(prg->player_pos);
    free(prg->exit_pos);
    if (prg->collectables_list->head)
        ft_lstclear(&(prg->collectables_list->head), &free);
    free(prg->collectables_list);
    if (prg->obstacles_list->head)
        ft_lstclear(&(prg->obstacles_list->head), &free);
    free(prg->obstacles_list);
    free(prg->mlx);
    int i = 0;

    while (i < prg->max_width)
    {
        free(prg->collect_pos[i]);
        i++;
    }
    free(prg->collect_pos);
    i = 0;
    while (i < prg->max_width)
    {
        free(prg->obst_pos[i]);
        i++;
    }
    free(prg->obst_pos);
    free(prg);
}


void    free_if_invalid_line(char *line, int fd, t_prg *prg, int error)
{
    free(line);
    BUFFER_SIZE = 0;
    get_next_line(fd);
    free_prg(prg);
    close(fd);
    errors(error);
}