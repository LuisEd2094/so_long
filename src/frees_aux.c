#include "so_long.h"
#include "get_next_line.h"


void free_rect(t_prg *prg)
{
    free(prg->player_pos);
    free(prg->exit_pos);
    if (prg->collectables_pos->head)
        ft_lstclear(&(prg->collectables_pos->head), &free);
    free(prg->collectables_pos);
    if (prg->obstacles_pos->head)
        ft_lstclear(&(prg->obstacles_pos->head), &free);
    free(prg->obstacles_pos);
    free(prg);
}


void    free_if_invalid_line(char *line, int fd, t_prg *prg, int error)
{
    free(line);
    BUFFER_SIZE = 0;
    get_next_line(fd);
    free_rect(prg);
    close(fd);
    errors(error);
}