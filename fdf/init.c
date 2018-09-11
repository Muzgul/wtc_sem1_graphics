/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:17:01 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/06 14:17:03 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			init_view(t_mlx_obj *o)
{
	t_mat4 r;

	r = add_zrotate(-45 * (M_PI / 180));
	o->m = mult_mat4(r, o->m);
	r = add_xrotate(-5 * (M_PI / 180));
	o->m = mult_mat4(r, o->m);
	r = add_yrotate(5 * (M_PI / 180));
	o->m = mult_mat4(r, o->m);
	r = add_downscale(0.3);
	o->m = mult_mat4(r, o->m);
	draw_grid(o);
}

t_mlx_obj		*get_mlx_obj(char **strarr, int width, int height, float fov)
{
	t_mlx_obj	*new_obj;

	new_obj = (t_mlx_obj *)malloc(sizeof(t_mlx_obj));
	new_obj->width = width;
	new_obj->height = height;
	new_obj->grid = point_grid(strarr);
	new_obj->m = perspective_mat(-1, -100, fov * (M_PI / 180));
	new_obj->mlx_ptr = mlx_init();
	new_obj->mlx_win = mlx_new_window(new_obj->mlx_ptr,
		width, height, "FDF_mmacdona");
	shift_x(new_obj->grid, (vcol_count(new_obj->grid) / 2) * -1);
	shift_y(new_obj->grid, (row_count((void **)new_obj->grid) / 2) * -1);
	init_view(new_obj);
	return (new_obj);
}
