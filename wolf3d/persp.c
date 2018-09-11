/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:57:52 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/15 15:57:53 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		camera_dist(t_mlx_obj o, float fov)
{
	float dist;

	dist = (o.width / 2) / (tan(fov / 2));
	return (dist);
}

t_mat2		get_rotate(float angle)
{
	t_mat2 m;

	m.a[0] = cos(angle);
	m.a[1] = -1 * (sin(angle));
	m.b[0] = sin(angle);
	m.b[1] = cos(angle);
	return (m);
}
