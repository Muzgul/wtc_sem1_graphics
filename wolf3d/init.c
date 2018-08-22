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

t_cam		init_cam(t_grid g, float fov)
{
	t_cam c;

	c.pos = init_vector(g.w/2, 0);
	c.dir = init_vector(0, 1);
	c.plane = cam_plane(c, fov);
	return (c);
}

t_mlx_obj	init_mlx(int height, int width)
{
	t_mlx_obj o;

	o.height = height;
	o.width = width;
	o.mlx_ptr = mlx_init();
	o.mlx_win = mlx_new_window(o.mlx_ptr, width, height, "WOLF3D");
	ft_putstr("done init\n");
	return (o);
}