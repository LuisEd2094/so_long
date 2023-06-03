#include "so_long.h"
#include "ft_printf.h"


    //line = NULL; ERRORS AND LINE COMMENT AS REMINDER ON HOW TO TEST ERRORS
    //errno = ENOMEM;
    //errno = EIO;

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
