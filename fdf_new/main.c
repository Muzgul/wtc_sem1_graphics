/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:57:08 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 10:57:10 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	draw_to_all(ft_vector **grid, ft_vector v, void *mlx_ptr, void *mlx_win)
{
	int i;
	int j;
	int space;

	space = 20;
	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j].null == 0)
		{
			if (grid[i][j].z == v.z && ((grid[i][j].x - v.x) < space && (grid[i][j].x - v.x) > (space * -1)) && ((grid[i][j].y - v.y) < space && (grid[i][j].y - v.y) > (space * -1)))
				draw_line(v, grid[i][j], mlx_ptr, mlx_win);
			j++;
		}
		i++;
	}
}

int     key_hook(int keycode)
{
    if (keycode == 53)
        exit (0);
	return (0);
}

int     main(int argc, char **argv)
{
	ft_vector	**grid;
	char		**strarr;
	int			fd;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("some.txt", O_RDONLY);
	strarr = read_to_array(fd);
	print_grid(strarr);
	grid = vector_grid(strarr);
	shift_z(grid, -20);
	print_vgrid(grid);
	shift_x(grid, (vcol_count(grid) / 2) * -1);
	shift_y(grid, (row_count((void **)grid) / 2) * -1);
	print_vgrid(grid);
	apply_transform(grid, scale_by, 10);
	print_vgrid(grid);
	shift_x(grid, 800);
	shift_y(grid, 450);
	// apply_transform(grid, to_negz, -1);
	// print_vgrid(grid);

	void *mlx_ptr;
	void *mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1600, 900, "Hello World!");
	mlx_key_hook(mlx_win, key_hook, NULL);
	

	int i;
	int j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j].null == 0)
		{
			draw_vector(grid[i][j], mlx_ptr, mlx_win);
			// if (grid[i][j].z == grid[3][3].z)
				draw_to_all(grid, grid[i][j], mlx_ptr, mlx_win);
			j++;
		}
		i++;
	}
	// draw_to_all(grid, grid[8][8], mlx_ptr, mlx_win);
	mlx_loop(mlx_ptr);
	return (0);
}
