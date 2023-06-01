#include "so_long.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int BUFFER_SIZE = 1024;

int main(int argc, char **argv)
{
    t_prg *prg;

    prg = parse_arguments(argc, argv);

    //ft_printf("Height %i Width %i", prg->height, prg->width);
   // print_list(prg->obstacles_list);    
    
    play_game(prg);
    //ft_printf("Valid Map\n");
    //free_prg(prg, 0);
/*
    t_position *pos1 = (t_position *)malloc(sizeof(t_position));
    pos1->x = 1;
    pos1->y = 2;

    t_position *pos2 = (t_position *)malloc(sizeof(t_position));
    pos2->x = 3;
    pos2->y = 4;


    //t_pos_list *list;
    t_list *node1 = ft_lstnew(pos1);
    t_list *node2 = ft_lstnew(pos2);


    t_pos_list pos_list;
    pos_list.head = NULL;


    ft_lstadd_front(&(pos_list.head), node1);
    ft_lstadd_front(&(pos_list.head), node2);
    //list->head = node;

    t_list *current = pos_list.head;
    while (current != NULL)
    {
        t_position *pos = (t_position *)(current->content);
       // printf("(%d, %d)\n", pos->x, pos->y);
       if (pos)
            break;
        current = current->next;
    }

    free(pos1);
    free(pos2);
    free(node1);
    free(node2);


    //ft_printf("%i\n", (* list)->head->content->x);
*/

}