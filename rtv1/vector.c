/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:15:55 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/30 11:15:56 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	vect_mult(t_vector v, double s)
{
	t_vector n;

	n.x = v.x * s;
	n.y = v.y * s;
	n.z = v.z * s;
	return (n);
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

t_vector	vect_add(t_vector v1, t_vector v2)
{
	t_vector res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vector	vect_sub(t_vector v1, t_vector v2)
{
	t_vector res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vector	vect_cross(t_vector v1, t_vector v2)
{
	t_vector n;

	n.x = v1.y * v2.z - v1.z * v2.y;
	n.y = v1.z * v2.x - v1.x * v2.z;
	n.z = v1.x * v2.y - v1.y * v2.x;
	return (n);
}

double		vect_dot(t_vector v1, t_vector v2)
{
	double res;

	res = v1.x * v2.x;
	res += v1.y * v2.y;
	res += v1.z * v2.z;
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

/* new search function that goes from src to t_max in dir and uses the object test fromt he struct to test if hit */

// double		vect_search(t_vector src, t_vector dir, double t_max, float (*is_hit)(t_vector))
// {
// 	t_vector	step;
// 	double		t;
// 	double		dist;
// 	double		temp;

// 	t = 1;
// 	while (t < t_max)
// 	{
// 		step = vect_add(src, vect_mult(dir, t));
// 		if ((dist = is_hit(step)) != -1)
// 			return (dist);
// 		t += (float)0.1;
// 	}
// 	return (-1);
// }
