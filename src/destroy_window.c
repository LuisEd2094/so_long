#include "so_long.h"


void    free_mlx(t_mlx *mlx)
{
    mlx_destroy_window(mlx->ptr, mlx->window);
    mlx_destroy_display(mlx->ptr);
    free(mlx->player);
    free(mlx->exit);
    free(mlx->collec);
    free(mlx->free);
    free(mlx->obst);
    free(mlx);
}