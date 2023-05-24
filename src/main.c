#include "../include/so_long.h"
#include "../include/ft_printf.h"

    void    parse_arguments(int argc, char **argv)
    {
        int fd;

        if (argc == 1 || argc > 2)
            errors(1);
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            ft_printf("Error\n%s\n", strerror(errno));
            exit(1);
        }

    }

    int main(int argc, char **argv)
    {
        parse_arguments(argc, argv);

        return 0;
    }