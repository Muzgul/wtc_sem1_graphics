/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:50:55 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/30 13:50:57 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	to_ndc(int x, int y, int w, int h)
{
	t_vector v;

	v.x = x + 0.5;
	v.x /= w;
	v.y = y + 0.5;
	v.y /= h;
	return (v);
}

t_vector	to_screen(t_vector ndc, double ar, double fov)
{
	t_vector v;

	v.x = (2 * ndc.x - 1) * ar * tan(fov / 2);
	v.y = (1 - 2 * ndc.y) * tan(fov / 2);
	return (v);
}

t_vector	cam_ray(int x, int y, t_m_img img, t_cam c)
{
	t_vector v;
	t_vector ndc;

	ndc = to_ndc(x, y, img.w, img.h);
	v = to_screen(ndc, img.w / img.h, c.fov);
	v.z = -1;
	return (v);
}

t_vector	cam_trans(t_cam c, t_vector ray)
{
	if (c.dir.z != 0 && c.dir.z != -1)
		ray = add_yrotate(ray, 180);
	if (c.dir.x != 0)
		ray = add_yrotate(ray, 90 * (c.dir.x / fabs(c.dir.x)));
	if (c.dir.y != 0)
		ray = add_xrotate(ray, -90 * (c.dir.y / fabs(c.dir.y)));
	ray = vect_norm(ray);
	return (ray);
}

void		trace(t_holder s)
{
	int			i;
	int			j;
	t_vector	ray;
	t_vector	rcb;

	i = 0;
	while (i < s.m.h)
	{
		j = 0;
		while (j < s.m.w)
		{
			ray = cam_trans(s.c, vect_norm(cam_ray(j, i, s.m, s.c)));
			rcb.x = shortest_dist(s.head, s.c.pos, ray, &rcb.y);
			if (rcb.x > 0)
			{
				rcb.z = light_intensity(s.head, s.light.pos,
					vect_mult(ray, rcb.x - 0.001));
				if (rcb.z > (double)0)
					mlx_pixel_put(s.mlx_ptr, s.mlx_win, j, i,
						adjust_colour(rcb.y, rcb.z, s.light.brightness));
			}
			j++;
		}
		i++;
	}
}
