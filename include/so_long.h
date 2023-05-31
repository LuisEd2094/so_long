#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
//include "mlx.h"


typedef struct t_s_position
{
    int x;
    int y;
} t_position;

typedef struct t_s_pos_list
{
    t_list *head;
}   t_pos_list;

typedef struct t_s_rect
{
    int height;
    int width;
    int current_line_width;
    int found_width;
    int valid_if_last_line;
    int player;
    t_position *player_pos;
    int exit;
    t_position *exit_pos;
    int collectables;
    t_pos_list *collectables_pos;  
    t_pos_list *obstacles_pos;  
}   t_prg;



extern  int BUFFER_SIZE;
void	errors(int val);
void    parse_arguments(int argc, char **argv);
void    check_file_type(char *argv);
t_prg  *init_prg_info(void);
void    free_if_invalid_line(char *line, int fd, t_prg *prg, int error);
int     check_if_valid_character(char chr);
void    check_if_EOF(int *is_EOF);
void    set_position(int *value, t_position *position, t_prg *prg);
void    free_rect(t_prg *prg);

#endif
