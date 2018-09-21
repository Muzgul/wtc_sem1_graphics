/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:52:47 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/31 10:52:48 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	vect_get(float x, float y, float z)
{
	t_vector v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_cam		cam_get(float zdir)
{
	t_cam c;

	c.pos = vect_get(0, 0, 0);
	c.dir = vect_get(0, 0, zdir);
	return (c);
}

t_point		point_get(t_vector o, t_vector d)
{
	t_point n;

	n.o = o;
	n.d = d;
	return (n);
}
