#include "so_long.h"


void    free_mlx(t_mlx *mlx)
{
    if (mlx->player)
        mlx_destroy_image (mlx->ptr, mlx->player);
    if (mlx->exit)
        mlx_destroy_image (mlx->ptr, mlx->exit);
    if (mlx->collec)
        mlx_destroy_image (mlx->ptr, mlx->collec);
    if (mlx->free)
        mlx_destroy_image (mlx->ptr, mlx->free);
    if (mlx->obst)
        mlx_destroy_image (mlx->ptr, mlx->obst);
    if (mlx->player_exit)
        mlx_destroy_image (mlx->ptr, mlx->player_exit);
    if (mlx->window)
        mlx_destroy_window(mlx->ptr, mlx->window);
    mlx_destroy_display(mlx->ptr);
    free(mlx->ptr);
}