/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:45:44 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/16 13:45:46 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_grid		init_grid(char **strarr)
{
	t_grid	g;
	char	**explode;

	check_input(strarr);
	g.grid = convert_to_int(strarr);
	explode = ft_strsplit(strarr[0], ' ');
	g.w = row_count((void **)explode);
	free_arr((void **)explode);
	g.h = row_count((void **)strarr);
	free_arr((void **)strarr);
	return (g);
}

t_vector	init_vector(float x, float y)
{
	t_vector v;

	v.x = x;
	v.y = y;
	return (v);
}

t_cam		init_cam(t_grid g)
{
	t_cam	c;
	int		i;
	int		j;

	i = 0;
	while (i < g.h)
	{
		j = 0;
		while (j < g.w)
		{
			if (g.grid[i][j] == 0)
			{
				c.pos = init_vector(j + 0.5, i + 0.5);
				c.dir = init_vector(-1, 0);
				c.plane = init_vector(0, 0.66);
				return (c);
			}
			j++;
		}
		i++;
	}
	print_err("No valid placement space!");
	exit(0);
}

t_mlx_obj	init_mlx(int height, int width)
{
	t_mlx_obj o;

	o.height = height;
	o.width = width;
	o.mlx_ptr = mlx_init();
	o.mlx_win = mlx_new_window(o.mlx_ptr, width, height, "WOLF3D");
	return (o);
}

void		init_hook(t_hold *hold)
{
	mlx_hook(hold->o.mlx_win, 2, 0, key_hook, hold);
	mlx_hook(hold->o.mlx_win, 17, 0, close_hook, hold);
}
