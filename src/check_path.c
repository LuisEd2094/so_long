#include "so_long.h"



#include "ft_printf.h"

/*
void init_row_col_val(int row[4], int col[4])
{
    row[0] = -1;
    row[1] = 1;
    row[2] = 0;
    row[3] = 0;
    col[0] = 0;
    col[1] = 00;
    col[2] = 1;
    col[3] = -1;
}

static int is_valid_move()

void    dept_first(int col, int row, t_prg *prg)
{
    t_position *new_pos;

    new_pos->x = row;
    new_pos->y = col;
    if (check_if_collide(new_pos, prg->collect_pos, 0 , 0))
        ft_printf("Found Collectable at %i col %i row\n", col, row);

    int row_change[4];
    int col_change[4];
    int new_row;
    int new_col;
    int i;

    init_row_col_val(row_change, col_change);
    i = 0;
    while (i < 4)
    {
        if (is_valid_move(prg, col_change[i], row_change[i]))
            dept_first();
        i++;
    }
    
    ft_printf("row %i col %i\n", row_change[0], col_change[0]);
}*/

void check_path(t_prg *prg)
{
    ft_printf("%i row %i col\n", prg->player_pos->y, prg->player_pos->x);
    ft_printf("%i\n", prg->obst_pos[2][3]);

    //dept_first(prg->player_pos->x, prg->player_pos->y, prg);
    return;
}