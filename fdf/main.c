#include "header.h"

int main(int argc, char **argv)
{
    int fd;

    if (argc > 1)
    {
        ft_putstr("Opening ... ");
        ft_putendl(argv[1]);
        fd = open(argv[1], O_RDONLY);
        read_to_array(fd);
    }
    return (0);
}