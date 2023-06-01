#include "so_long.h"




void get_list_to_array(t_list *current, int **array)
{
    t_list *temp;
    t_position *pos;
    
    pos  = current->content;
    temp = current->next;
    while (current)
    {
        temp = current->next;
        pos = current->content;
        array[pos->x][pos->y] = 1;
        current = temp;
    } 
}

void    get_internal_obst(t_prg *prg)
{
    t_list *current;
    t_list *temp;
    t_position *pos;

    current = prg->obstacles_list->head;
    temp = current->next;
    pos  = current->content; 
    while (pos->y == prg->height - 1)
    {
        free(pos);
        free(current);
        current =  temp;
        temp = current->next;
        pos = current->content;
    }  
    prg->obstacles_list->head = current;
}


void  get_obstacles_and_collectables_to_arrays(t_prg  *prg)
{
    get_internal_obst(prg);
    get_list_to_array(prg->collectables_list->head, (prg->collect_pos));
    get_list_to_array(prg->obstacles_list->head, (prg->obst_pos));
}


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