#include "so_long.h"
#include "ft_printf.h"


void    get_window_size(t_prg * prg)
{
    prg->winw_width = prg->width * 64;
    prg->winw_height = prg->height * 64;
}
void    init_mlx_vars(t_prg *prg)
{
    prg->mlx->ptr = mlx_init();
    if(!prg->mlx->ptr)
        free_prg(prg, 2);
    get_window_size(prg);
    prg->mlx->window = mlx_new_window(prg->mlx->ptr, prg->winw_width, prg->winw_height, "so_long");
    if (!prg->mlx->window)
        free_prg(prg, 2);
    prg->mlx->free = mlx_xpm_file_to_image(prg->mlx->ptr, "./imgs/clover-1.xpm", &(prg->winw_width), &(prg->winw_height));
    prg->mlx->obst = mlx_xpm_file_to_image(prg->mlx->ptr, "./imgs/Yellow-green_crystal1.xpm", &(prg->winw_width),  &(prg->winw_height));
//// NEED TO CHECK IF IMGS LOAD IF NOT NEED TO FREE PROGRAM AND RETURN ERROR
}

void first_draw(t_prg *prg)
{
    int i;
    int j;

    i = 0;
    while (i < prg->width)
    {
        j = 0;
        while (j < prg->height)
        {
            if (i == 0 || i == prg->width - 1 || j == 0 || j == prg->height - 1)
                mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->obst, i * 64, j * 64);

            j++;
        }
        i++;
    }
} 

void play_game(t_prg *prg)
{

    init_mlx_vars(prg);
    first_draw(prg);

/*
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 0);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 64);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 128);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 192);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, 0, 256);
*/
    ft_printf("valid %i\n", prg->obst_pos[1][1]);
/*
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
*/
    mlx_loop(prg->mlx->ptr);


}