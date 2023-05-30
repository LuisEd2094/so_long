#include "so_long.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int BUFFER_SIZE = 1024;

int main(int argc, char **argv)
{
    parse_arguments(argc, argv);
    ft_printf("Valid Map\n");


    void * mlx = mlx_init();

    ft_printf("%p\n", mlx);
    void *mlx_window = mlx_new_window(mlx, 600, 300, "test");

    long i = 1;

    while(i)
    {
        i++;

        //ft_printf("HOLA\n");

        if (i == 10000000000)
        {
            mlx_destroy_window(mlx, mlx_window);
            ft_printf("DONE\n");
            break;
        }

    }

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
    exit(EXIT_SUCCESS);
}