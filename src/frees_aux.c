#include "so_long.h"
#include "get_next_line.h"

void *free_array(int **array, int length)
{
    int i;

    i = 0;
    if (array)
    {
        while (i < length)
        {
            if (array[i])
                free(array[i++]);
            else
                break;
        }   
        free(array);
    }
    return (NULL);

}

void free_pos_list(t_pos_list *pos_list)
{
    if(pos_list->head)
        ft_lstclear(&(pos_list->head), &free);
    free(pos_list);
}

void free_prg(t_prg *prg, int error)
{
    if (prg->player_pos)
        free(prg->player_pos);
    if (prg->exit_pos)
        free(prg->exit_pos);
    if (prg->collectables_list)
        free_pos_list(prg->collectables_list);
    if (prg->obstacles_list)
        free_pos_list(prg->obstacles_list);
    if (prg->collect_pos)
        free_array(prg->collect_pos, prg->max_width);
    if (prg->obst_pos)
        free_array(prg->obst_pos, prg->max_width);
    if (prg->visited)
        free_array(prg->visited, prg->max_width);
    if (prg->mlx)
        free(prg->mlx);
    if (prg)
        free(prg);
    if (!error)
        exit(EXIT_SUCCESS);
    else if (error == 2)
        errors(2);
}

void    free_if_invalid_line(char *line, int fd, t_prg *prg, int error)
{
    free(line);
    BUFFER_SIZE = 0;
    get_next_line(fd);
    free_prg(prg, 1);
    close(fd);
    errors(error);
}