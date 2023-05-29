#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct t_s_rect
{
    int height;
    int rect_width;
    int current_line_width;
    int found_width;
    int valid_if_last_line;    
}   t_rect;

extern  int BUFFER_SIZE;
void	errors(int val);
void    parse_arguments(int argc, char **argv);

#endif
