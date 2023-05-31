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
    new_prg->player_pos = (t_position *)malloc(sizeof(t_position));
    new_prg->exit_pos = (t_position *)malloc(sizeof(t_position));
    new_prg->collectables_pos = (t_pos_list *)malloc(sizeof(t_pos_list));
    new_prg->collectables_pos->head = NULL;
    new_prg->obstacles_pos = (t_pos_list *)malloc(sizeof(t_pos_list));
    new_prg->obstacles_pos->head = NULL; 
    new_prg->mlx =(t_mlx *)malloc(sizeof(t_mlx));
    return(new_prg);
}