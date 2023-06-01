#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"

int close_game(t_prg *prg)
{
    free_mlx(prg);
    free_prg(prg, 0);
    return (0);
}

int key_hook(int key, t_prg *prg)
{
    //leaving this here to check values in the future 
    //ft_printf("key %i\n", key);
    if (key == KEY_ESC || key == KEY_Q)
        close_game(prg);
    return (0);
}


void    get_hooks(t_prg *prg)
{
    mlx_hook(prg->mlx->window, 17, 0, close_game,(void *)prg);
    mlx_key_hook(prg->mlx->window, key_hook, (void *)prg);

}