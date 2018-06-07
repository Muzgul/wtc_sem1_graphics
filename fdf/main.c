#include "header.h"

int main(int argc, char **argv)
{
    int         fd;
    mlx_ctrl    *my_mlx;

    if (argc > 1)
    {
        my_mlx = NULL;
        initialise_mlx(&my_mlx);
        new_window(my_mlx, 1080, 720, "Hello World!");
        

        ft_putstr("Opening ");
        ft_putstr(argv[1]);
        ft_putendl("...");
        fd = open(argv[1], O_RDONLY);
        my_mlx->map = read_to_array(fd);     
        // print_array(my_mlx->map);
        draw_array(my_mlx);

        run_loop(my_mlx);
    }
    return (0);
}