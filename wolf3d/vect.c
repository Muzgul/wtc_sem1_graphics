/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:02:56 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/21 09:02:57 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float		vect_dist(t_vector v1, t_vector v2)
{
	float dist;
	float difx;
	float dify;

	difx = pow(v2.x - v1.x, 2);
	dify = pow(v2.y - v1.y, 2);
	dist = sqrt(difx + dify);
	return (dist);
}

t_vector	vect_add(t_vector v1, t_vector v2)
{
	t_vector v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return (v);
}

t_vector	vect_rotate(t_vector v, float angle)
{
	t_mat2		m;
	t_vector	t;

	m = mat2_rotate(angle);
	t = mat2_apply(v, m);
	return (t);
}
