/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:00:31 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/04 13:00:32 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     main(int argc, char **argv)
{
	char		**strarr;
	int			fd;
    ft_mlx_obj	*mlx_obj;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("some.txt", O_RDONLY);
	strarr = read_to_array(fd);
	print_grid(strarr);
	mlx_obj = get_mlx_obj(strarr, 900, 1600, 90);
	
	mlx_key_hook(mlx_obj->mlx_win, key_hook, mlx_obj);

	//ft_mat4 t = add_xrotate(90 * (M_PI/180));
	// print_vgrid(grid);
	draw_grid(mlx_obj);

	// draw_to_all(grid, temp, mlx_ptr, mlx_win);
	
	mlx_loop(mlx_obj->mlx_ptr);

    return (0);
}
