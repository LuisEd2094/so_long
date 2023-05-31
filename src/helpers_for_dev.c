#include "so_long.h"
#include "ft_printf.h"


void	print_list(t_pos_list *pos_list)
{
    t_list *current = pos_list->head;
    while (current != NULL)
    {
        t_position *pos = (t_position *)(current->content);
        printf("(%d, %d)\n", pos->x, pos->y);
        current = current->next;
    }
}
