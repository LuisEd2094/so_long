#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "mlx.h"


typedef struct t_s_position
{
    int x;
    int y;
} t_position;

typedef struct t_s_pos_list
{
    t_list *head;
}   t_pos_list;


typedef struct  t_s_mlx
{
    void    *ptr;
    void    *window;
    void    *player;
    void    *exit;
    void    *collec;
    void    *free;
    void    *obst;

}   t_mlx;

typedef struct t_s_prg
{
    int height;
    int width;
    int current_line_width;
    int found_width;
    int valid_if_last_line;
    int player;
    int collectables;
    int exit;
    int max_width;
    int max_height;
    t_position *player_pos;
    t_position *exit_pos;
    t_pos_list *collectables_pos;  
    t_pos_list *obstacles_pos;
    t_mlx   *mlx;

}   t_prg;



extern  int BUFFER_SIZE;
void	errors(int val);
t_prg   *parse_arguments(int argc, char **argv);
void    check_file_type(char *argv);
t_prg  *init_prg_info(void);
void    free_if_invalid_line(char *line, int fd, t_prg *prg, int error);
int     check_if_valid_character(char chr);
void    check_if_EOF(int *is_EOF);
void    set_position(int *value, t_position *position, t_prg *prg);
void    free_prg(t_prg *prg);


/////// HELPERS FOR DEV ////

void	print_list(t_pos_list *pos_list);
#endif
