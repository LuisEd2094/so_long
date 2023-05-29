#include "so_long.h"

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
    new_rect->valid_if_last_line = 1;
    new_rect->player = 0;
    new_rect->exit = 0;
    new_rect->collectables = 0;
    new_rect->player_pos = (t_position *)malloc(sizeof(t_position));
    new_rect->exit_pos = (t_position *)malloc(sizeof(t_position));
    new_rect->collectables_pos = (t_pos_list *)malloc(sizeof(t_pos_list));
    new_rect->collectables_pos->head = NULL;
    new_rect->obstacles_pos = (t_pos_list *)malloc(sizeof(t_pos_list));
    new_rect->obstacles_pos->head = NULL; 
    return(new_rect);
}