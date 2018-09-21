/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:28:06 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/21 10:28:08 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			check_ex(char **ex)
{
	int i;

	if (ex == NULL)
		return (-1);
	i = 0;
	while (ex[i] != NULL)
		i++;
	return (i);
}

double		calc_res(t_vector abc)
{
	double		delta;
	double		res;
	t_vector	v;

	res = 0;
	delta = pow(abc.y, 2) - 4 * abc.x * abc.z;
	v = vect_get((-1 * abc.y + sqrt(delta)) / (2 * abc.x), (-1 * abc.y -
		sqrt(delta)) / (2 * abc.x), -1 * (abc.y / (2 * abc.x)));
	if (delta > 0.001)
	{
		if (v.x > (double)0 && v.y > (double)0 && v.x < v.y)
			res = v.x;
		if (v.x > (double)0 && v.y > (double)0 && !(v.x < v.x))
			res = v.y;
		if (v.x > (double)0 && !(v.y > (double)0))
			res = v.x;
		if (v.y > (double)0 && !(v.x > (double)0))
			res = v.y;
	}
	if (delta < 0.001 && delta > -0.001)
		res = v.z;
	return (res);
}

double		vect_get_dist(t_vector f, t_vector t)
{
	float dx;
	float dy;
	float dz;
	float dist;

	dx = pow(t.x - f.x, 2);
	dy = pow(t.y - f.y, 2);
	dz = pow(t.z - f.z, 2);
	dist = sqrt(dx + dy + dz);
	return (dist);
}

t_vector	vect_norm(t_vector v)
{
	t_vector	n;
	double		dist;

	dist = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
	dist = sqrt(dist);
	n = vect_get(v.x / dist, v.y / dist, v.z / dist);
	return (n);
}
