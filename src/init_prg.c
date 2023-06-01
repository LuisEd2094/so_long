#include "so_long.h"

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
    new_prg->player_pos = (t_position *)malloc(sizeof(t_position));
    new_prg->exit_pos = (t_position *)malloc(sizeof(t_position));
    new_prg->collectables_list = (t_pos_list *)malloc(sizeof(t_pos_list));
    new_prg->collectables_list->head = NULL;
    new_prg->obstacles_list = (t_pos_list *)malloc(sizeof(t_pos_list));
    new_prg->obstacles_list->head = NULL; 
    new_prg->mlx =(t_mlx *)malloc(sizeof(t_mlx));
    new_prg->obst_pos = (int **)malloc(sizeof(int *) *new_prg->max_width);
    int i = 0;
    while (i < new_prg->max_width)
    {
        new_prg->obst_pos[i++] = (int *)malloc(sizeof(int) *new_prg->max_height);
    }

    new_prg->collect_pos = (int **)malloc(sizeof(int *) *new_prg->max_width);
    i = 0;
    while (i < new_prg->max_width)
    {
        new_prg->collect_pos[i++] = (int *)malloc(sizeof(int) *new_prg->max_height);
    }
    return(new_prg);
}