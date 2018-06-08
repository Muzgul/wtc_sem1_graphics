#include "header.h"

//calls draw point
void draw_array(mlx_ctrl *my_mlx)
{
    ft_putendl("Drawing map...");
    int i;

    i = 0;
    while (my_mlx->map[i] != NULL)
    {
        draw_row(my_mlx, i);
        i++;
    }
}

void draw_row(mlx_ctrl *my_mlx, int row)
{
    int i;

    i = 0;
    while (my_mlx->map[row][i] != '\0')
    {
        if (ft_isdigit(my_mlx->map[row][i]))
        {
            draw_point(my_mlx, row, i);
        }
        i++;
    }
}

void draw_point(mlx_ctrl *my_mlx, int row, int point)
{
    int x_off;
    int y_off;
    int pos_x;
    int pos_y;
    int color;

    x_off = (my_mlx->resX - my_mlx->map_w) / 2 - ((my_mlx->zoom * my_mlx->map_w) / 2);
    y_off = (my_mlx->resY - my_mlx->map_h) / 2  - (((my_mlx->zoom + my_mlx->camY) * my_mlx->map_h) / 2);
    pos_x = x_off + (point * my_mlx->zoom) + (point * my_mlx->zoom); //(point + row) * space ish
    pos_y = y_off + (row * (my_mlx->zoom + my_mlx->camY));//(pointmax - point + row) * space ish ish look at book pg 1
    color = 16777215 - ft_atoi(&my_mlx->map[row][point]) * 10000;
    mlx_pixel_put(my_mlx->mlx_ptr, my_mlx->mlx_win, pos_x, pos_y, color);
}