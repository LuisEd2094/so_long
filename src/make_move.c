#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"

int is_in_exit(t_position *player, t_position *exit)
{
    if (player->x == exit->x && player->y == exit->y)
        return (1);
    return (0);
}

void make_visual_move(t_prg *prg, int x_chg, int y_chg)
{
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->player, (prg->player_pos->x + x_chg) * 64, (prg->player_pos->y + y_chg) * 64);
    if(is_in_exit(prg->player_pos, prg->exit_pos))
        mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->exit, prg->player_pos->x * 64, prg->player_pos->y * 64);
    else
        mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->free, prg->player_pos->x * 64, prg->player_pos->y * 64);
    prg->player_pos->x += x_chg;
    prg->player_pos->y += y_chg;
    if(is_in_exit(prg->player_pos, prg->exit_pos))
        mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->mlx->player_exit, prg->player_pos->x * 64, prg->player_pos->y * 64);
}

int make_move(t_prg * prg, int x_chg, int y_chg)
{
    make_visual_move(prg, x_chg, y_chg); 
    if (prg->collectables == 0 && is_in_exit(prg->player_pos, prg->exit_pos))
    {
        ft_printf("You won the game, nice job!\n");
        close_game (prg);
    }
    else if (check_if_collide(prg->player_pos, prg->collect_pos, 0 , 0))
    {
        prg->collect_pos[prg->player_pos->x][prg->player_pos->y] = 0;
        prg->collectables--;
    }
    prg->moves++;
    ft_printf("You have made %i moves so far!\n", prg->moves);
    return (1);
}