#include "so_long.h"



#include "ft_printf.h"


void init_row_col_val(int *row, int * col)
{
    row[0] = -1;
    row[1] = 1;
    row[2] = 0;
    row[3] = 0;
    col[0] = 0;
    col[1] = 0;
    col[2] = 1;
    col[3] = -1;
}

//static int is_valid_move();
/*
void    dept_first(int col, int row, t_prg *prg)
{
    t_position *new_pos;

    new_pos->x = row;
    new_pos->y = col;
    if (check_if_collide(new_pos, prg->collect_pos, 0 , 0))
        ft_printf("Found Collectable at %i col %i row\n", col, row);

    int new_row;
    int new_col;
    int i;

    i = 0;
    while (i < 4)
    {
       // if (is_valid_move(prg, col_change[i], row_change[i]))
            //continue;
        i++;
    }
    
}
*/
void check_path(t_prg *prg)
{
    ft_printf("%i row %i col\n", prg->player_pos->y, prg->player_pos->x);
    ft_printf("%i\n", prg->obst_pos[2][3]);
    init_row_col_val(prg->row_change, prg->col_change);
    ft_printf("%i COL %i row", prg->col_change[2], prg->row_change[0]);

    //dept_first(prg->player_pos->x, prg->player_pos->y, prg);
    return;
}