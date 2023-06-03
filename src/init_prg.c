#include "so_long.h"

int **create_2d_array(int width, int height)
{
    int i;
    int j;
    int **array;

    array = (int **)malloc(sizeof(int *) * width);
    if (!array)
        return (NULL);
    i = 0;
    while (i < width)
    {

        array[i] = (int *)malloc(sizeof(int) * width);
        if (!array[i])
            return (free_array(array, i));
        j = 0; 
        while (j < height)
            array[i][j++] = 0;
        i++;
    }
    return(array);
}

void    check_if_any_fail(t_prg *new_prg)
{
    if (!new_prg->player_pos || !new_prg->exit_pos || !new_prg->collectables_list \
        || !new_prg->obstacles_list || !new_prg->mlx || !new_prg->obst_pos \
        || !new_prg->collect_pos)
        free_prg(new_prg, 2);
    return;
}

void    init_mlx(t_mlx *mlx)
{   
    mlx->ptr = NULL;
    mlx->window = NULL;
    mlx->player = NULL;
    mlx->exit = NULL;
    mlx->collec = NULL;
    mlx->free = NULL;
    mlx->obst = NULL;
    mlx->player_exit = NULL;
}

void    init_mallocs(t_prg *new_prg)
{
    new_prg->player_pos = (t_position *)malloc(sizeof(t_position));
    new_prg->exit_pos =  (t_position *)malloc(sizeof(t_position));
    new_prg->collectables_list = (t_pos_list *)malloc(sizeof(t_pos_list));
    if (new_prg->collectables_list)
        new_prg->collectables_list->head = NULL;
    new_prg->obstacles_list = (t_pos_list *)malloc(sizeof(t_pos_list));
    if (new_prg->obstacles_list)
        new_prg->obstacles_list->head = NULL;
    new_prg->mlx = (t_mlx *)malloc(sizeof(t_mlx));
    new_prg->obst_pos = create_2d_array(new_prg->max_width, new_prg->max_height);
    new_prg->collect_pos = create_2d_array(new_prg->max_width, new_prg->max_height);
    check_if_any_fail(new_prg);
}

#include "errno.h"
t_prg *init_prg_info(void)
{
    t_prg *new_prg;

    new_prg = (t_prg *)malloc(sizeof(t_prg));
    if (!new_prg)
        errors(2);
    new_prg->current_line_width = 0;
    new_prg->height = 0;
    new_prg->width = 0;
    new_prg->found_width = 0;
    new_prg->valid_if_last_line = 1;
    new_prg->player = 0;
    new_prg->exit = 0;
    new_prg->collectables = 0;
    new_prg->max_width = 20;
    new_prg->max_height = 12;
    new_prg->winw_height = 0;
    new_prg->winw_width = 0;
    new_prg->sqr_size = 64;
    new_prg->moves = 0;
    init_mallocs(new_prg);
    init_mlx(new_prg->mlx);
    return(new_prg);
}