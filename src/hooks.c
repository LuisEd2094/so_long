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

int is_valid_move(t_prg* prg, int x_chg, int y_chg)
{
    if (no_border_collision(prg, x_chg, y_chg) && \
    !check_if_collide(prg->player_pos, prg->obst_pos, x_chg , y_chg))
        return (1);
    return (0);
}

int is_in_exit(t_position *player, t_position *exit)
{
    if (player->x == exit->x && player->y == exit->y)
        return (1);
    return (0);
}

int make_move(t_prg * prg, int x_chg, int y_chg)
{
    ft_printf("Collectable count %i\n", prg->collectables);
    prg->player_pos->x += x_chg;
    prg->player_pos->y += y_chg;
    //MAKE VISUAL MOVE HERE 
    if (prg->collectables == 0 && is_in_exit(prg->player_pos, prg->exit_pos))
        close_game (prg); // END GAME
    else if (check_if_collide(prg->player_pos, prg->collect_pos, 0 , 0))
    {
        prg->collectables--;
        ft_printf("I picked up a collectable\nCollectables remaining %i\n", prg->collectables);
    }

    return (1);
}

int key_hook(int key, t_prg *prg)
{
    //leaving this here to check values in the future 
    //ft_printf("key %i\n", key);
    if (key == KEY_ESC || key == KEY_Q)
        close_game(prg);
    else if (key == KEY_W && is_valid_move(prg, 0, -1))
        return (make_move(prg, 0, -1));
    else if (key == KEY_A && is_valid_move(prg, -1, 0))
        return (make_move(prg, -1, 0));
    else if (key == KEY_D && is_valid_move(prg, 1, 0))
        return (make_move(prg, 1, 0));
    else if (key == KEY_S && is_valid_move(prg, 0 , 1))
        return (make_move(prg, 0 , 1));
    return (0);
}


void    get_hooks(t_prg *prg)
{
    mlx_hook(prg->mlx->window, 17, 0, close_game,(void *)prg);
    mlx_key_hook(prg->mlx->window, key_hook, (void *)prg);
}