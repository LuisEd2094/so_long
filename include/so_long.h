#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "keys.h"
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
    void    *player_exit;

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
    int winw_width;
    int winw_height;
    int sqr_size;
    int moves;
    t_position *player_pos;
    t_position *exit_pos;
    t_pos_list *collectables_list;  
    t_pos_list *obstacles_list;
    t_mlx   *mlx;
    int **obst_pos;
    int **collect_pos;
    int **visited;
    int *row_change;
    int *col_change;
    int col_found;
    int exit_found;

}   t_prg;



extern  int BUFFER_SIZE;
t_prg  *init_prg_info(void);

t_prg   *parse_arguments(int argc, char **argv);
void    set_position(int *value, t_position *position, t_prg *prg);
void    get_obstacles_and_collectables_to_arrays(t_prg  *prg);
int     add_pos_to_list(t_pos_list *list, int x, int y);


void    check_if_EOF(int *is_EOF);
int     check_if_valid_character(char chr);
int     check_height_width(t_prg *prg);
void    check_file_type(char *argv);
void    check_line(int  *is_EOF, char *line, t_prg *prg, int fd);
void    check_path(t_prg *prg);
int     check_if_collide(t_position *pos, int **pos_to_check, int x_chg, int y_chg);
int     is_in_exit(t_position *player, t_position *exit);
int     no_border_collision(t_prg* prg, int x_chg, int y_chg);







void    get_hooks(t_prg *prg);
int     key_hook(int key, t_prg *prg);
int     make_move(t_prg * prg, int x_chg, int y_chg);


void play_game(t_prg *prg);



void	errors(int val);


void    free_prg(t_prg *prg, int error);
void*    free_array(int **array, int length);
void    free_if_invalid_line(char *line, int fd, t_prg *prg, int error);
void    free_mlx(t_mlx *mlx);
int     close_game(t_prg *prg);
int     check_if_collide(t_position *pos, int **pos_to_check, int x_chg, int y_chg);




/////// HELPERS FOR DEV ////

void	print_list(t_pos_list *pos_list);
#endif
