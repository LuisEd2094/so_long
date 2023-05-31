#include "so_long.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int BUFFER_SIZE = 1024;

int main(int argc, char **argv)
{
    t_prg *prg;

    prg = parse_arguments(argc, argv);
    ft_printf("Valid Map\n");
    //ft_printf("Height %i Width %i", prg->height, prg->width);
    print_list(prg->obstacles_list);    
    


    


    int width = 1280;
    int height = 768;



    prg->mlx->ptr = mlx_init();
    if (!prg->mlx->ptr)
        return -1;

    prg->mlx->window = mlx_new_window(prg->mlx->ptr, width, height, "Image Drawing");

    // Create a new image
    prg->mlx->player = mlx_xpm_file_to_image(prg->mlx->ptr, "./imgs/clover-1.xpm", &width, &height);
    prg->mlx->exit = mlx_xpm_file_to_image(prg->mlx->ptr, "./imgs/Yellow-green_crystal1.xpm", &width, &height);

    if (!prg->mlx->player)
    {
        mlx_destroy_window(prg->mlx->ptr, prg->mlx->window);
        mlx_destroy_display(prg->mlx->ptr);
        free(prg->mlx->ptr);
        return -1;
    }

    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 0);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 64);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 128);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 192);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 256);

    ft_printf("valid %i\n", prg->obst_pos[1][1]);

    int i = 1;
    int j = 1;

    ft_printf("%i\n", prg->width);

    while (i < prg->width)
    {
        j = 1;
        while (j < prg->height)
        {
            if (prg->obst_pos[i][j])
                mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, i * 64, j * 64);
            else
                mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->player, i * 64, j * 64);
            j++;
            ft_printf("I value %i, J value %i\n", i, j);
            ft_printf("%i COORDINATE\n", prg->obst_pos[i][j]);
        }
        i++;
        ft_printf("HOLA\n");
    }

    mlx_loop(prg->mlx->ptr);

    return 0;


    free_prg(prg);
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