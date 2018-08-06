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

int     key_hook(int keycode, ft_mlx_obj *o)
{
    ft_mat4 r;

    if (keycode == 53)
        exit (0);
    if (keycode == 12)
    {
        r = add_zrotate(5 * (M_PI/180));
        o->m = mult_mat4(r, o->m);
        draw_grid(o);
    }
    if (keycode == 14)
    {
        r = add_zrotate(-5 * (M_PI/180));
        o->m = mult_mat4(r, o->m);
        draw_grid(o);
    }
    if (keycode == 13)
    {
        r = add_xrotate(5 * (M_PI/180));
        o->m = mult_mat4(r, o->m);
        draw_grid(o);
    }
    if (keycode == 1)
    {
        r = add_xrotate(-5 * (M_PI/180));
        o->m = mult_mat4(r, o->m);
        draw_grid(o);
    }
    if (keycode == 0)
    {
        r = add_yrotate(5 * (M_PI/180));
        o->m = mult_mat4(r, o->m);
        draw_grid(o);
    }
    if (keycode == 2)
    {
        r = add_yrotate(-5 * (M_PI/180));
        o->m = mult_mat4(r, o->m);
        draw_grid(o);
    }
	return (0);
}
