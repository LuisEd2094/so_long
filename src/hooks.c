#include "so_long.h"
#include "mlx.h"




int close_window(t_prg *prg)
{
    //free(prg);
    free_mlx(prg->mlx);
    free_prg(prg, 0);
    return (0);
}

void    get_hooks(t_prg *prg)
{
    mlx_hook(prg->mlx->window, 17, 0, close_window,(void *)prg);
}