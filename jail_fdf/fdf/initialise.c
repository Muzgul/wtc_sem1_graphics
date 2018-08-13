#include "header.h"

void    initialise_mlx(mlx_ctrl **my_mlx)
{
    (*my_mlx) = (mlx_ctrl *)malloc(sizeof(mlx_ctrl));
    (*my_mlx)->mlx_ptr = mlx_init();
    (*my_mlx)->mlx_win = NULL;
    (*my_mlx)->map = NULL;
    (*my_mlx)->map_w = 0;
    (*my_mlx)->map_h = 0;
    (*my_mlx)->zoom = 5;
    (*my_mlx)->resX = 0;
    (*my_mlx)->resY = 0;
    (*my_mlx)->camX = 0;
    (*my_mlx)->camY = 0;
}

void    initialise_map(mlx_ctrl *my_mlx, int fd)
{
    read_save(fd, my_mlx);
}

void    run_loop(mlx_ctrl *my_mlx)
{
    mlx_key_hook(my_mlx->mlx_win, key_hook, my_mlx);
    mlx_mouse_hook(my_mlx->mlx_win, mouse_hook, my_mlx);
    mlx_expose_hook(my_mlx->mlx_win, expose_hook, my_mlx);
}