#include "so_long.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int BUFFER_SIZE = 1024;

int main(int argc, char **argv)
{
    parse_arguments(argc, argv);
    ft_printf("Valid Map\n");    
    
    /*
    void *mlx_ptr;
    void *mlx_window;
    void *image_ptr;

    int width = 640;
    int height = 426;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return -1;

    mlx_window = mlx_new_window(mlx_ptr, width, height, "Image Drawing");

    // Create a new image
    image_ptr = mlx_xpm_file_to_image(mlx_ptr, "sample_640×426.xpm", &width, &height);
    if (!image_ptr)
    {
        mlx_destroy_window(mlx_ptr, mlx_window);
        mlx_destroy_display(mlx_ptr);
        printf("HOLA");
        free(mlx_ptr);
        return -1;
    }

    mlx_put_image_to_window(mlx_ptr, mlx_window, image_ptr, 0, 0);

    mlx_loop(mlx_ptr);

    return 0;*/

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