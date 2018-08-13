/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:38:12 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/04 14:38:15 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_xrotate(int keycode, t_mlx_obj *o)
{
	t_mat4 r;

	if (keycode == 13)
	{
		r = add_xrotate(5 * (M_PI / 180));
		o->m = mult_mat4(r, o->m);
		draw_grid(o);
	}
	if (keycode == 1)
	{
		r = add_xrotate(-5 * (M_PI / 180));
		o->m = mult_mat4(r, o->m);
		draw_grid(o);
	}
}

void	check_yrotate(int keycode, t_mlx_obj *o)
{
	t_mat4 r;

	if (keycode == 0)
	{
		r = add_yrotate(5 * (M_PI / 180));
		o->m = mult_mat4(r, o->m);
		draw_grid(o);
	}
	if (keycode == 2)
	{
		r = add_yrotate(-5 * (M_PI / 180));
		o->m = mult_mat4(r, o->m);
		draw_grid(o);
	}
}

void	check_zrotate(int keycode, t_mlx_obj *o)
{
	t_mat4 r;

	if (keycode == 12)
	{
		r = add_zrotate(5 * (M_PI / 180));
		o->m = mult_mat4(r, o->m);
		draw_grid(o);
	}
	if (keycode == 14)
	{
		r = add_zrotate(-5 * (M_PI / 180));
		o->m = mult_mat4(r, o->m);
		draw_grid(o);
	}
}

void	check_zoom(int keycode, t_mlx_obj *o)
{
	t_mat4 r;

	if (keycode == 15)
	{
		r = add_upscale(2);
		o->m = mult_mat4(r, o->m);
		draw_grid(o);
	}
	if (keycode == 3)
	{
		r = add_downscale(0.5);
		o->m = mult_mat4(r, o->m);
		draw_grid(o);
	}
}

int		key_hook(int keycode, t_mlx_obj *o)
{
	if (keycode == 53)
	{
		free_grid(o->grid);
		mlx_destroy_window(o->mlx_ptr, o->mlx_win);
		free(o);
		exit(0);
	}
	check_xrotate(keycode, o);
	check_yrotate(keycode, o);
	check_zrotate(keycode, o);
	check_zoom(keycode, o);
	return (0);
}
