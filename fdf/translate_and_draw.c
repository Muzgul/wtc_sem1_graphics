#include "header.h"

//calls draw point
void draw_array(mlx_ctrl *my_mlx)
{
    int i;
    int x_off;
    int y_off;

    i = 0;
    x_off = ft_strlen(*(my_mlx->map));
    y_off = row_count(my_mlx->map);
    while (my_mlx->map[i] != NULL)
    {
        draw_row(my_mlx->mlx_ptr, my_mlx->map[i]);
        ft_putchar('\n');
        i++;
    }
}

void draw_row(void *mlx_ptr, char *row)
{
    int i;

    i = 0;
    while (row[i] != '\0')
    {
        if (ft_isdigit(row[i]))
        {
            draw_point(mlx_ptr, row[i]);
        }
        i++;
    }
}

char draw_point(void *mlx_ptr, char c)
{
    if (mlx_ptr)
        ft_putchar(c);
    return (c);
}