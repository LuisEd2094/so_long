#include "so_long.h"


void    free_mlx(t_prg *prg)
{
    mlx_destroy_image (prg->mlx->ptr,prg->mlx->player);
    mlx_destroy_image (prg->mlx->ptr,prg->mlx->exit);
    mlx_destroy_image (prg->mlx->ptr,prg->mlx->collec);
    mlx_destroy_image (prg->mlx->ptr,prg->mlx->free);
    mlx_destroy_image (prg->mlx->ptr,prg->mlx->obst);
    mlx_destroy_image (prg->mlx->ptr,prg->mlx->player_exit);
    mlx_destroy_window(prg->mlx->ptr, prg->mlx->window);
    mlx_destroy_display(prg->mlx->ptr);
    free(prg->mlx->ptr);
}