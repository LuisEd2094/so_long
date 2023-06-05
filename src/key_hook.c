#include "so_long.h"

int no_border_collision(t_prg *prg, int x_chg, int y_chg)
{
    if (prg->player_pos->x + x_chg < prg->width - 1 && \
        prg->player_pos->y + y_chg < prg->height -1 && \
        prg->player_pos->x + x_chg > 0 && \
        prg->player_pos->y +y_chg > 0)
        return (1);
    return (0);
}

static int is_valid_move(t_prg* prg, int x_chg, int y_chg)
{
    if (no_border_collision(prg, x_chg, y_chg) && \
    !check_if_collide(prg->player_pos, prg->obst_pos, x_chg , y_chg))
        return (1);
    return (0);
}

int key_hook(int key, t_prg *prg)
{
    //ft_printf("%i\n", key); // CHECKER OF KEYS VALUES
    if (key == KEY_ESC || key == KEY_Q)
        close_game(prg);
    else if ((key == KEY_W || key == KEY_UP) && is_valid_move(prg, 0, -1))
        return (make_move(prg, 0, -1));
    else if ((key == KEY_A || key == KEY_LFT) && is_valid_move(prg, -1, 0))
        return (make_move(prg, -1, 0));
    else if ((key == KEY_D || key == KEY_RGT) && is_valid_move(prg, 1, 0))
        return (make_move(prg, 1, 0));
    else if ((key == KEY_S || key == KEY_DOWN) && is_valid_move(prg, 0 , 1))
        return (make_move(prg, 0 , 1));
    return (0);
}