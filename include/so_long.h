#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"


typedef struct t_s_position
{
    int x;
    int y;
} t_position;

typedef struct t_s_rect
{
    int height;
    int rect_width;
    int current_line_width;
    int found_width;
    int valid_if_last_line;
    int player;
    t_position *player_pos;
    int exit;
    t_position *exit_pos;
    int collectables;    
}   t_rect;

typedef struct t_s_pos_list
{
    t_list *head;
}   t_pos_list;

extern  int BUFFER_SIZE;
void	errors(int val);
void    parse_arguments(int argc, char **argv);

#endif
