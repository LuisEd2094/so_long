#include "so_long.h"
#include "ft_printf.h"

int BUFFER_SIZE = 1024;

int main(int argc, char **argv)
{
    t_prg *prg;

    prg = parse_arguments(argc, argv);
    //play_game(prg);
    ft_printf("Valid Map\n");
    free_prg(prg, 0);
}