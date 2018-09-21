/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 14:10:24 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/31 14:10:27 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		test_circle(int size, t_vector co, t_point r)
{
	t_vector	roco;
	double		trco;
	double		d;
	double		tpco;

	roco = vect_sub(co, r.o);
	trco = vect_dot(roco, r.d);
	if (trco >= 0)
	{
		d = vect_dot(roco, roco) - pow(trco, 2);
		d = sqrt(d);
		if (d >= 0)
		{
			tpco = sqrt(pow(size, 2) - pow(d, 2));
			if (trco - tpco > 0.0001 && trco - tpco < trco + tpco)
				return (trco - tpco);
			if (trco + tpco > 0.0001 && trco + tpco < trco - tpco)
				return (trco + tpco);
		}
	}
	return (0);
}

double		test_plane(t_point p, t_point r)
{
	double	den;

	den = vect_dot(r.d, p.d);
	if (den > 0.0001 || den < -0.0001)
	{
		return (vect_dot(p.d, vect_sub(p.o, r.o)) / den);
	}
	return (0);
}

double		test_disk(t_point p, t_point r, int size)
{
	double		t;
	t_vector	v;

	if ((t = test_plane(p, r)) > 0)
	{
		v = vect_add(r.o, vect_mult(r.d, t));
		v = vect_sub(v, p.o);
		if (vect_dot(v, v) <= pow(size, 2))
			return (t);
	}
	return (0);
}

double		test_cylinder(t_point p, t_point r, t_vector size)
{
	t_vector	abc;
	t_vector	v;

	v = vect_sub(r.d, vect_mult(p.d, vect_dot(r.d, p.d)));
	abc.x = vect_dot(v, v);
	v = vect_sub(r.o, p.o);
	abc.y = vect_dot(vect_sub(r.d, vect_mult(p.d, vect_dot(r.d, p.d))),
			vect_sub(v, vect_mult(p.d, vect_dot(v, p.d))));
	abc.y *= 2;
	v = vect_sub(v, vect_mult(p.d, vect_dot(v, p.d)));
	abc.z = vect_dot(v, v) - pow(size.x, 2);
	return (calc_res(abc));
}

double		test_cone(t_point p, t_point r, t_vector size)
{
	t_vector	abc;
	t_vector	v;
	double		res;

	if (size.z == 0)
		size.z = tan(size.x / size.y);
	else
		size.z = angl(size.z);
	size.x = size.y * tan(size.z);
	abc.x = pow(vect_dot(r.d, p.d), 2) - ((1 + cos(size.z)) / 2);
	v = vect_sub(r.o, p.o);
	abc.y = vect_dot(r.d, p.d) * vect_dot(v, p.d) -
		vect_dot(r.d, v) * ((1 + cos(size.z)) / 2);
	abc.y *= 2;
	abc.z = pow(vect_dot(v, p.d), 2) -
		vect_dot(v, v) * ((1 + cos(size.z)) / 2);
	res = calc_res(abc);
	if (vect_dot(p.d, vect_sub(r.o, p.o)) + res * vect_dot(p.d, r.d) > 0)
	{
		if (size.y == 0 || (size.y != 0 && vect_dot(p.d, vect_sub(r.o, p.o))
			+ res * vect_dot(p.d, r.d) < size.y))
			return (res);
	}
	return (0);
}
