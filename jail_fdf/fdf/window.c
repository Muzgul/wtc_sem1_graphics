#include "header.h"

void    new_window(mlx_ctrl *my_mlx, int res_x, int res_y, char *title)
{
    my_mlx->resX = res_x;
    my_mlx->resY = res_y;
    my_mlx->mlx_win = mlx_new_window(my_mlx->mlx_ptr, res_x, res_y, title);
}

int     key_hook(int keycode, mlx_ctrl *my_mlx)
{
    if (keycode == 53)
        exit (0);
    if (keycode == 12)
        my_mlx->zoom += 1;
    if (keycode == 14)
        my_mlx->zoom -= 1;
    if (keycode == 13)
        my_mlx->camY += 1;
    if (keycode == 1)
        my_mlx->camY -= 1;
    if (keycode == 0)
        my_mlx->camX += 1;
    if (keycode == 2)
        my_mlx->camX -= 1;
    expose_hook(my_mlx);
    return (0);
}

int mouse_hook(int button,int x,int y,void *param)
{
    if (param == NULL)
        param = NULL;
    ft_putstr("Button Press: ");
    ft_putnbr(button);
    ft_putchar('\n');
    ft_putstr("At: ");
    ft_putnbr(x);
    ft_putchar(',');
    ft_putnbr(y);
    ft_putchar('\n');
    return (0);
}

int expose_hook(mlx_ctrl *my_mlx)
{
    if (my_mlx)
        return (1);
    //mlx_clear_window(my_mlx->mlx_ptr, my_mlx->mlx_win);
    //draw_array(my_mlx);   
    return (0);
}