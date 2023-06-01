#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"

int close_game(t_prg *prg)
{
    free_mlx(prg);
    free_prg(prg, 0);
    return (0);
}

int no_border_collision(t_prg* prg, int x_chg, int y_chg)
{
    if (prg->player_pos->x + x_chg < prg->width - 1 && \
        prg->player_pos->y + y_chg < prg->height -1 && \
        prg->player_pos->x + x_chg > 0 && \
        prg->player_pos->y +y_chg > 0)
        return (1);
    return (0);
}

int no_obstacle_collision(t_prg* prg, int x_chg, int y_chg)
{
    return 1;
}

int is_valid_move(t_prg* prg, int x_chg, int y_chg)
{
    ft_printf("width %i height %i\n", prg->width, prg->height);
    ft_printf("player X pos %i player y pos %i\n", prg->player_pos->x, prg->player_pos->y);

    if (no_border_collision(prg, x_chg, y_chg) && no_obstacle_collision(prg, x_chg, y_chg))
    {
        prg->player_pos->x += x_chg;
        prg->player_pos->y += y_chg;
    }
    else
        ft_printf("invalid position\n");
    ft_printf("player X pos %i player y pos %i\n", prg->player_pos->x, prg->player_pos->y);


    return (1);

}

int key_hook(int key, t_prg *prg)
{
    //leaving this here to check values in the future 
    //ft_printf("key %i\n", key);
    if (key == KEY_ESC || key == KEY_Q)
        close_game(prg);
    else if (key == KEY_W && is_valid_move(prg, 0, -1))
        return (1);
    else if (key == KEY_A && is_valid_move(prg, -1, 0))
        return (1);
    else if (key == KEY_D && is_valid_move(prg, 1, 0))
        return (1);
    else if (key == KEY_S && is_valid_move(prg, 0 , 1))
        return (1);
    return (0);
}


void    get_hooks(t_prg *prg)
{
    mlx_hook(prg->mlx->window, 17, 0, close_game,(void *)prg);
    mlx_key_hook(prg->mlx->window, key_hook, (void *)prg);

}