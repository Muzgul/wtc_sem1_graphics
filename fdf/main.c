#include "header.h"

void    print_grid(char **grid)
{
    int i;

    i = 0;
    while (grid[i] != NULL)
    {
        ft_putendl(grid[i]);
        i++;
    }
}

void    draw_grid(mlx_ctrl *my_mlx, char **grid)
{
    int i;
    int j;
    int *p;

    i = 0;
    while (grid[i] != NULL)
    {
        j = 0;
        while (grid[i][j] != '\0')
        {
            if (ft_isdigit(grid[i][j]))
            {
                p = make_point(j * 10, i * 10, ft_atoi(&grid[i][j]));
                if (p != NULL)
                {
                    temp_draw_point(my_mlx, p);
                    free(p);
                }
            }
            j++;
        }
        i++;
    }
}

int     draw_to_prev(mlx_ctrl *my_mlx, int x, int y, char **grid)
{
    int tx;
    int ty;
    int *p;
    int *p2;

    tx = x;
    ty = y - 1;
    p = make_point(x * 10, y * 10, ft_atoi(&grid[y][x]));
    while (ty > 0 && tx > 0 && ft_isdigit(grid[ty][tx]) == 0 && grid[ty][tx] != grid[y][x])
        ty--;
    if ((tx == x && ty == y) || ty < 0 || grid[ty][tx] != grid[y][x])
        p2 = NULL;
    else
        p2 = make_point(tx * 10, ty * 10, ft_atoi(&grid[ty][tx]));
    temp_draw_line(my_mlx, p, p2);
    if (p2 != NULL)
        free(p2);
    else
        ty = y;
    tx = x - 1;
    while (tx > 0 && ft_isdigit(grid[ty][tx]) == 0 && grid[ty][tx] != grid[y][x])
        tx--;
    if ((tx == x && ty == y) || tx < 0 || grid[ty][tx] != grid[y][x])
        p2 = NULL;
    else
        p2 = make_point(tx * 10, ty * 10, ft_atoi(&grid[ty][tx]));
    temp_draw_line(my_mlx, p, p2);
    if (p2 != NULL)
        free(p2);
    return (1);
}

void    draw_grid_lines(mlx_ctrl *my_mlx, char **grid)
{
    int i;
    int j;

    i = 0;
    while (grid[i] != NULL)
    {
        j = 0;
        while (grid[i][j] != '\0')
        {
            if (ft_isdigit(grid[i][j]))
            {
                draw_to_prev(my_mlx, j, i, grid);
            }
            j++;
        }
        i++;
    }
}

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
        char **map = read_to_array(fd);
        print_grid(map);
        draw_grid(my_mlx, map);
        draw_grid_lines(my_mlx, map);
        run_loop(my_mlx);
        mlx_loop(my_mlx->mlx_ptr);
    }
    return (0);
}