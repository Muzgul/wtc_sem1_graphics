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

double		test_box(t_object *o, t_vector ro, t_vector rd)
{
	double tmin = -INFINITY;
	double tmax = INFINITY;
	t_vector v1;
	t_vector v2;

	if (rd.x != 0.0) {
		v1.x = (vect_sub(vect_add(o->origin, o->n), o->size).x - ro.x)/rd.x;
		v2.x = (vect_add(vect_add(o->origin, o->n), o->size).x - ro.x)/rd.x;

		tmin = max(tmin, min(v1.x, v2.x));
		tmax = min(tmax, max(v1.x, v2.x));
	}

	if (rd.y != 0.0) {
		v1.y = (vect_sub(vect_add(o->origin, o->n), o->size).y - ro.y)/rd.y;
		v2.y = (vect_add(vect_add(o->origin, o->n), o->size).y - ro.y)/rd.y;

		tmin = max(tmin, min(v1.y, v2.y));
		tmax = min(tmax, max(v1.y, v2.y));
	}

	if (rd.y != 0.0) {
		v1.z = (vect_sub(vect_add(o->origin, o->n), o->size).z - ro.z)/rd.z;
		v2.z = (vect_add(vect_add(o->origin, o->n), o->size).z - ro.z)/rd.z;

		tmin = max(tmin, min(v1.z, v2.z));
		tmax = min(tmax, max(v1.z, v2.z));
	}
	return tmax >= tmin;
}

double		test_object(t_object *o, t_vector ro, t_vector rd)
{
	if (test_box(o, ro, rd) > 0)
	{
			ft_putendl("HEY WE HAVE A COLLISION!!!");
		if (ft_strcmp(o->type, "Sphere") == 0)
			return (test_circle(o->size.x, o->origin, ro, rd));
		if (ft_strcmp(o->type,  "Plane") == 0)
			return (test_plane(o->origin, o->n, ro, rd));
	}
	return (-1);
}

double		test_circle(int size, t_vector co, t_vector ro, t_vector rd)
{
	// t_vector	res;
	// double		delta;
	// double		root;
	// double		root2;

	// a = (x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2
	// b = 2( (x2 - x1)(x1 - x3) + (y2 - y1)(y1 - y3) +(z2 - z1)(z1 - z3) )
	// c = x3^2 + y3^2 + z3^2 + x1^2 + y1^2 + z1^2 -2( x3*x1 + y3*y1 + z3*z1 ) - r^2
	// rayt = vect_mult(ray, tmax);
	// res.x = pow(rayt.x - ray.x, 2) + pow(rayt.y - ray.y, 2) + pow(rayt.z - ray.z, 2);
	// res.y = (rayt.x - ray.x) * (ray.x - origin.x) + (rayt.y - ray.z) * (ray.y - origin.y) + (rayt.z - ray.z) * (ray.z - origin.z);
	// res.y *= 2;
	// res.z = pow(origin.x, 2) + pow(origin.y, 2) + pow(origin.z, 2) + pow(ray.x, 2) + pow(ray.y, 2) + pow(ray.z, 2) - 2 * (origin.x * ray.x + origin.y * ray.y + origin.z * ray.z) - pow(size, 2);
	// res.x = pow(ray.x, 2) + pow(ray.y, 2) + pow(ray.z, 2);
	// res.y = ray.x * (-1 * origin.x) + ray.y * (-1 * origin.y) + ray.z * (-1 * origin.z);
	// res.y *= 2;
	// res.z = pow(origin.x, 2) + pow(origin.y, 2) + pow(origin.z, 2) - pow(size, 2);
	// delta = pow(res.y, 2) - (4 * res.x * res.z);
	// if (delta > 0)
	// {
	// 	root = ((-1 * res.y) + sqrt(delta)) / (2 * res.x);
	// 	if (root > 0)
	// 		return (root);
	// 	root = ((-1 * res.y) - sqrt(delta)) / (2 * res.x);
	// 	return (root);
	// }
	// if (delta == 0)
	// {
	// 	root = -1 * (res.y / (2 * res.x));
	// 	return (root);
	// }
	t_vector roco;
	double trco;
	double d;
	double tpco;

	roco = vect_sub(co, ro);	
	trco = vect_dot(roco, rd);
	if (trco >=0 )
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

double		test_plane(t_vector po, t_vector pn,  t_vector ro, t_vector rd)
{
	double	den;

	den = vect_dot(rd, pn);
	if (den > 0.0001 || den < -0.0001)
	{
		return (vect_dot(pn, vect_sub(po, ro)) / den);
	}
	return (0);
}
