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
    prg->mlx->free = mlx_xpm_file_to_image(prg->mlx->ptr, "./imgs/empty.xpm", &(prg->winw_width), &(prg->winw_height));
    prg->mlx->obst = mlx_xpm_file_to_image(prg->mlx->ptr, "./imgs/obst.xpm", &(prg->winw_width),  &(prg->winw_height));
    prg->mlx->player = mlx_xpm_file_to_image(prg->mlx->ptr, "./imgs/player.xpm", &(prg->winw_width),  &(prg->winw_height));
    prg->mlx->exit = mlx_xpm_file_to_image(prg->mlx->ptr, "./imgs/door.xpm", &(prg->winw_width),  &(prg->winw_height));
    prg->mlx->collec = mlx_xpm_file_to_image(prg->mlx->ptr, "./imgs/collect.xpm", &(prg->winw_width),  &(prg->winw_height));

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
            if (i == 0 || i == prg->width - 1 || j == 0 || j == prg->height - 1 || prg->obst_pos[i][j])
                mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->obst, i * 64, j * 64);
            else if (prg->collect_pos[i][j])
                mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->collec, i * 64, j * 64);
            else 
                mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->free, i * 64, j * 64);

            j++;
        }
        i++;
    }
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->player, prg->player_pos->x * 64, prg->player_pos->y * 64);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, prg->exit_pos->x * 64, prg->exit_pos->y * 64);
} 

void play_game(t_prg *prg)
{

    init_mlx_vars(prg);
    first_draw(prg);
    mlx_loop(prg->mlx->ptr);
}