#include "mytest.h"

int main(int argc, char **argv)
{
    ft_putendl("Hello world!");
    if (argc > 1)
    {
        ft_putendl(argv[1]);
    }
    ft_putendl("testMlx:");
    if (testMlx() == 0)
        ft_putendl("SUCCESS!");
    return (0);
}

int testMlx(void)
{
    void    *mlx_ptr;
    void    *mlx_win;
    int     loop_ret;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
    {
        ft_putendl("Returned NULL");
        return (1);
    }
    else
        ft_putendl("Returned Something!");

    ft_putendl("New Window: Hello World!");
    mlx_win = mlx_new_window(mlx_ptr, 1000, 500, "Hello World!");
    if (mlx_win == NULL)
    {
        ft_putendl("Returned Null");
        return (1);
    }
    else
        ft_putendl("Did a thing!");
    //Draw Dots
    for (int i = 0; i < 1000; i += 10)
    {
        
        for (int j = 0; j < 1000; j++)
        {
            mlx_pixel_put(mlx_ptr, mlx_win, i-1, j+i-1, 0x00212121);
            mlx_pixel_put(mlx_ptr, mlx_win, i, j+i, 0x00212121);
            mlx_pixel_put(mlx_ptr, mlx_win, i+1, j+i+1, 0x00212121);
        }

        mlx_pixel_put(mlx_ptr, mlx_win, i, i, 0x00FFFFFF);
    }

    //Add loop control 
    void *param = NULL;
    mlx_key_hook(mlx_win, key_hook, param);

    mlx_mouse_hook(mlx_win, mouse_hook, param);

    ft_putendl("Started Loop");
    loop_ret = mlx_loop(mlx_ptr);

    return (0);
}

int key_hook(int keycode, void *param)
{
    if (param == NULL)
        param = NULL;
    ft_putendl("Keycode: ");
    ft_putnbr(keycode);
    if (keycode == 53)
        exit (0);
    else return (1);
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