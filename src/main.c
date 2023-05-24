#include "../include/so_long.h"
#include "../include/ft_printf.h"

    void    parse_arguments(int argc, char **argv)
    {
        int fd;

        if (argc == 1 || argc > 2)
            errors(1);
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
            errors(2);

    }

    int main(int argc, char **argv)
    {
        parse_arguments(argc, argv);

        return 0;
    }