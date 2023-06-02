#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"

int close_game(t_prg *prg)
{
    free_mlx(prg->mlx);
    free_prg(prg, 0);
    return (0);
}

int check_if_collide(t_position *pos, int **pos_to_check, int x_chg, int y_chg)
{
    int new_x;
    int new_y;

    new_x = pos->x + x_chg;
    new_y = pos->y + y_chg;
    if (pos_to_check[new_x][new_y])
        return (1);
    return (0);
}

void    get_hooks(t_prg *prg)
{
    mlx_hook(prg->mlx->window, 17, 0, close_game,(void *)prg);
    mlx_key_hook(prg->mlx->window, key_hook, (void *)prg);
}