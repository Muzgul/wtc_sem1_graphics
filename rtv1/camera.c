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
	v.z = -1;
	return (v);
}

t_vector	to_screen(t_vector ndc, double ar, double fov)
{
	t_vector v;

	v.x = (2 * ndc.x - 1) * ar * tan(fov / 2);
	v.y = (1 - 2 * ndc.y) * tan(fov / 2);
	v.z = ndc.z;
	return (v); 
}

t_vector	cam_ray(int x, int y, t_m_img img, t_cam c)
{
	t_vector v;
	t_vector ndc;

	ndc = to_ndc(x, y, img.w, img.h);
	v = to_screen(ndc, img.w / img.h, c.fov);
	return (v);
}
