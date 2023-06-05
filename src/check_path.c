#include "so_long.h"


#include "errno.h"
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

static int is_valid(t_prg *prg, int col, int row)
{
    if (col < prg->width -1 && row < prg->height -1 \
    && col > 0 && row > 0 && !prg->visited[col][row])
        return (1);
    return (0);
}

int check_if_done(t_prg *prg)
{
    if ((prg->col_found == prg->collectables && prg->exit_found) \
    || errno)
        return (1);
    return (0);
}

void    depth_first(int col, int row, t_prg *prg)
{
    t_position *new_pos;
    int         i;

    new_pos = (t_position *)malloc(sizeof(t_position));
    if (!new_pos)
        return; 
    prg->visited[col][row] = 1;
    new_pos->x = col;
    new_pos->y = row;
    if (check_if_collide(new_pos, prg->collect_pos, 0, 0))
        prg->col_found++;
    if (is_in_exit(new_pos, prg->exit_pos))
        prg->exit_found = 1;
    i = 0;
    while (i < 4)
    {
        new_pos->x = col + prg->col_change[i];
        new_pos->y = row + prg->row_change[i];
        if (is_valid(prg, new_pos->x, new_pos->y) && \
        !check_if_collide(new_pos, prg->obst_pos, 0, 0))
            depth_first(new_pos->x, new_pos->y, prg);
        if (check_if_done(prg))
            break;
        i++;
    }
    free(new_pos); 
}

void check_path(t_prg *prg)
{
    init_row_col_val(prg->row_change, prg->col_change);
    depth_first(prg->player_pos->x, prg->player_pos->y, prg);
    if (prg->col_found == prg->collectables && prg->exit_found)
        return;
    free_prg(prg, 8);
    errors(8);
}