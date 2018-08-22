/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:51:50 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/21 07:51:52 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_cam	rotate_cam(t_cam c, float angle)
{
	t_mat2	m;

	m = mat2_rotate(angle);
	c.dir = mat2_apply(c.dir, m);
	return (c);
}

float	cam_plane(t_cam c, float fov)
{
	t_vector	temp;
	float		dist;
	float		plane;

	temp = init_vector(c.pos.x + c.dir.x, c.pos.y + c.dir.y);
	dist = vect_dist(c.pos, temp);
	plane = dist * tan(fov / 2);
	return (plane);
}
