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
