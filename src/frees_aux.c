#include "so_long.h"
#include "get_next_line.h"


void free_rect(t_rect *rect_info)
{
    free(rect_info->player_pos);
    free(rect_info->exit_pos);
    if (rect_info->collectables_pos->head)
        ft_lstclear(&(rect_info->collectables_pos->head), &free);
    free(rect_info->collectables_pos);
    if (rect_info->obstacles_pos->head)
        ft_lstclear(&(rect_info->obstacles_pos->head), &free);
    free(rect_info->obstacles_pos);
    free(rect_info);
}


void    free_if_invalid_line(char *line, int fd, t_rect *rect_info, int error)
{
    free(line);
    BUFFER_SIZE = 0;
    get_next_line(fd);
    free_rect(rect_info);
    close(fd);
    errors(error);
}