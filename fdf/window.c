#include "header.h"

void    initialise_mlx(mlx_ctrl **my_mlx)
{
    (*my_mlx) = (mlx_ctrl *)malloc(sizeof(mlx_ctrl));
    (*my_mlx)->mlx_ptr = mlx_init();
    (*my_mlx)->param = NULL;
    (*my_mlx)->zoom = 10;
}

void    run_loop(mlx_ctrl *my_mlx)
{
    mlx_key_hook(my_mlx->mlx_win, key_hook, my_mlx->param);
    mlx_mouse_hook(my_mlx->mlx_win, mouse_hook, my_mlx->param);
    mlx_loop(my_mlx->mlx_ptr);
}

void    new_window(mlx_ctrl *my_mlx, int res_x, int res_y, char *title)
{
    my_mlx->mlx_win = mlx_new_window(my_mlx->mlx_ptr, res_x, res_y, title);
}

int     key_hook(int keycode, void *param)
{
    param = NULL;
    if (keycode == 53)
        exit (0);
    else 
        return (1);
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