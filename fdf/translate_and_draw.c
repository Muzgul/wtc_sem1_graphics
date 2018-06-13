#include "header.h"

//calls draw point
void draw_array(mlx_ctrl *my_mlx)
{
    ft_putendl("Drawing map...");
    int i;

    i = 0;
    while (i < my_mlx->map_h)
    {
        draw_row(my_mlx, i);
        i++;
    }
}

void draw_row(mlx_ctrl *my_mlx, int row)
{
    int i;

    i = 0;
    while (i < my_mlx->map_w)
    {
        draw_point(my_mlx, row, i);
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

    x_off = (my_mlx->resX - my_mlx->map_w) / 2;
    y_off = (my_mlx->resY - my_mlx->map_h) / 2;
    pos_x = x_off + calculate_x(my_mlx, row, point);
    pos_y = y_off + calculate_y(my_mlx, row, point);
    color = 16777215 - my_mlx->map[row][point] * 10000;
    mlx_pixel_put(my_mlx->mlx_ptr, my_mlx->mlx_win, pos_x, pos_y, color);
}

int calculate_x(mlx_ctrl *my_mlx, int row, int point)
{
    int pos_x;

    pos_x = (point + row) * my_mlx->zoom;
    return (pos_x);
}

int calculate_y(mlx_ctrl *my_mlx, int row, int point)
{
    int pos_y;

    pos_y = (my_mlx->map_w - point + row) * my_mlx->zoom - (my_mlx->map[row][point]) * my_mlx->camY;
    if (my_mlx->camY != 0)
    {
        if (my_mlx->camY < 0)
            pos_y /= my_mlx->camY;
        else
            pos_y /= my_mlx->camY;
    }
    return (pos_y);
}