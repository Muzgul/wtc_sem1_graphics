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
	// shift_z(grid, -20);
	// print_vgrid(grid);
	apply_transform(grid, scale_by, 5);
	print_vgrid(grid);
	apply_transform(grid, to_negz, -1);
	print_vgrid(grid);

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
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
