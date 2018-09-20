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
#include <stdio.h>

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
	if (rd.z != 0.0) {
		v1.z = (vect_sub(vect_add(o->origin, o->n), o->size).z - ro.z)/rd.z;
		v2.z = (vect_add(vect_add(o->origin, o->n), o->size).z - ro.z)/rd.z;
		tmin = max(tmin, min(v1.z, v2.z));
		tmax = min(tmax, max(v1.z, v2.z));
	}
	return tmax >= tmin;
}

double		test_object(t_object *o, t_vector ro, t_vector rd)
{
	if (ft_strcmp(o->type, "Sphere") == 0)
		return (test_circle(o->size.x, o->origin, ro, rd));
	if (ft_strcmp(o->type,  "Plane") == 0)
		return (test_plane(o->origin, o->n, ro, rd));
	if (ft_strcmp(o->type, "Disk") == 0)
		return (test_disk(o->origin, o->n, ro, rd, o->size.x));
	if (ft_strcmp(o->type, "Cylinder") == 0)
		return (test_cylinder(o->origin, o->n, ro, rd, o->size));
	if (ft_strcmp(o->type, "Cone") == 0)
		return (test_cone(o->origin, o->n, ro, rd, o->size));
	return (-1);
}

double		test_object_shadow(t_object *o, t_vector ro, t_vector rd)
{
	if (ft_strcmp(o->type, "Sphere") == 0)
		return (test_circle(o->size.x, o->origin, ro, rd));
	if (ft_strcmp(o->type,  "Plane") == 0)
		return (test_plane(o->origin, o->n, ro, rd));
	if (ft_strcmp(o->type, "Disk") == 0)
		return (test_disk(o->origin, o->n, ro, rd, o->size.x));
	if (ft_strcmp(o->type, "Cylinder") == 0)
		return (test_cylinder(o->origin, o->n, ro, rd, o->size));
	if (ft_strcmp(o->type, "Cone") == 0)
		return (test_cone_shadow(o->origin, o->n, ro, rd, o->size));
	return (-1);
}

double		test_circle(int size, t_vector co, t_vector ro, t_vector rd)
{
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

double		test_disk(t_vector po, t_vector pn, t_vector ro, t_vector rd, int size)
{
	double		t;
	t_vector	v;

	if ((t = test_plane(po, pn, ro, rd)) > 0)
	{
		v = vect_add(ro, vect_mult(rd, t));
		v = vect_sub(v, po);
		if (vect_dot(v, v) <= pow(size, 2))
			return (t);
	}
	return (0);
}

double		test_cylinder(t_vector po, t_vector pn, t_vector ro, t_vector rd, t_vector size)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	t_vector	v;

	//pa = po
	//va = pn
	//p = ro
	//v = rd
	//delta = p - pa
	//(v - (v . va)va)^2
	v = vect_sub(rd, vect_mult(pn, vect_dot(rd, pn)));
	a = vect_dot(v, v);
	//2(v - (v . va)va   .   (p - pa)-((p - pa) . va)va)
	v = vect_sub(ro, po);
	b = vect_dot(vect_sub(rd, vect_mult(pn, vect_dot(rd, pn))), vect_sub(v, vect_mult(pn, vect_dot(v, pn))));
	b *= 2;
	//((p - pa) - ((p - pa) . va)va)^2 - r^2
	v = vect_sub(v, vect_mult(pn, vect_dot(v, pn)));
	c = vect_dot(v, v) - pow(size.x, 2);
	delta = pow(b, 2) - 4 * a * c;
	v.x = (-1 * b + sqrt(delta)) / (2 * a);
	v.y = (-1 * b - sqrt(delta)) / (2 * a);
	v.z = -1 * (b / (2 * a));
	// ft_putendl("Cylinder");
	// v = vect_cross(rd, vect_sub(pn, po));
	// a = vect_dot(v, v);
	// b = vect_dot(v, vect_cross(vect_sub(ro, po), vect_sub(pn, po)));
	// b *= 2;
	// v = vect_cross(vect_sub(ro, po), vect_sub(pn, po));
	// c = vect_dot(v, v) - (pow(size.x, 2) * vect_dot(vect_sub(pn, po),vect_sub(pn, po)));
	// delta = pow(b, 2) - 4 * a * c;
	// v.x = (-1 * b + sqrt(delta)) / (2 * a);
	// v.y = (-1 * b - sqrt(delta)) / (2 * a);
	// v.z = -1 * (b / (2 * a));
	double res;
	res = 0;
	if (delta > -0.001)
	{
		if (delta > 0.001)
		{
			if (v.x > 0.001)
				res = v.x;
			if (v.y > 0.001)
				res = v.y;
		}
		if (delta < 0.001 && delta > -0.001)
			res = v.z;
		// if (size.y != 0)
		// {
		// 	v = vect_mult(rd, res);
		// 	v = vect_sub(v, po);
		// 	v = vect_mult(pn, vect_dot(v, pn) / vect_dot(pn, pn));
		// 	if (fabs(vect_dot(v, pn)) < size.y)
		// 		return (res);
		// 	double another;
		// 	if ((another = test_disk(vect_add(vect_mult(pn, size.y), po), pn, ro, rd, size.x)) > 0.001)
		// 		return (another);
		// 	if ((another = test_disk(vect_add(vect_mult(pn, size.y * -1), po), pn, ro, rd, size.x)) > 0.001)
		// 		return (another);
		// }
		// else
		return (res);
	}
	return (0);
}

double		test_cone(t_vector po, t_vector pn, t_vector ro, t_vector rd, t_vector size)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	t_vector	v;
	double		res = 0;

	if (size.z == 0)
		size.z = tan(size.x / size.y);
	else
	{
		size.z = angl(size.z);
		size.x = size.y * tan(size.z);
	}
	if (size.z != 0)
	{		
		a = pow(vect_dot(rd, pn), 2) - ((1 + cos(size.z)) / 2);
		v = vect_sub(ro, po);
		b = vect_dot(rd, pn) * vect_dot(v, pn) - vect_dot(rd, v) * ((1 + cos(size.z)) / 2);
		b *= 2;
		c = pow(vect_dot(v, pn), 2) - vect_dot(v, v) * ((1 + cos(size.z)) / 2);
		delta = pow(b, 2) - 4 * a * c;
		v.x = (-1 * b + sqrt(delta)) / (2 * a);
		v.y = (-1 * b - sqrt(delta)) / (2 * a);
		v.z = -1 * (b / (2 * a));
		if (delta >= (double)0)
		{
			if (delta > 0.001)
			{
				if (v.x > (double)0 && v.y > (double)0)
				{
					// if (v.x < 1)
					// 	printf("Both +: t0(%f) t1(%f) delta(%f) a(%f) b(%f) c(%f) ***\n", v.x, v.y, delta, a, b, c);
					// else
					// 	printf("Both +: t0(%f) t1(%f) delta(%f) a(%f) b(%f) c(%f)\n", v.x, v.y, delta, a, b, c);
					if (v.x < v.y)
						res = v.x;
					else
						res = v.y;
				}
				else
				{
					if (v.x > (double)0)
						res = v.x;
					if (v.y > (double)0)
						res = v.y;
				}
			}
			if (delta < 0.001 && delta > -0.001)
				res = v.z;
			if (vect_dot(vect_sub(vect_mult(rd, res), po), pn) > 0)
			{
				if (size.y != 0)
				{
					if (vect_dot(vect_sub(vect_mult(rd, res), po), pn) < size.y)
						return (res);
				}
				else
					return (res);
			}
		}
	}
	return (0);
}

double		test_cone_shadow(t_vector po, t_vector pn, t_vector ro, t_vector rd, t_vector size)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	t_vector	v;
	double		res = 0;

	if (size.z == 0)
		size.z = tan(size.x / size.y);
	else
	{
		size.z = angl(size.z);
		size.x = size.y * tan(size.z);
	}
	if (size.z != 0)
	{		
		a = pow(vect_dot(rd, pn), 2) - ((1 + cos(size.z)) / 2);
		v = vect_sub(ro, po);
		b = vect_dot(rd, pn) * vect_dot(v, pn) - vect_dot(rd, v) * ((1 + cos(size.z)) / 2);
		b *= 2;
		c = pow(vect_dot(v, pn), 2) - vect_dot(v, v) * ((1 + cos(size.z)) / 2);
		delta = pow(b, 2) - 4 * a * c;
		v.x = (-1 * b + sqrt(delta)) / (2 * a);
		v.y = (-1 * b - sqrt(delta)) / (2 * a);
		v.z = -1 * (b / (2 * a));
		if (delta >= (double)0)
		{
			if (delta > 0.001)
			{
				if (v.x > (double)0 && v.y > (double)0)
				{
					// if (v.x < 1)
					// 	printf("Both +: t0(%f) t1(%f) delta(%f) a(%f) b(%f) c(%f) ***\n", v.x, v.y, delta, a, b, c);
					// else
					// 	printf("Both +: t0(%f) t1(%f) delta(%f) a(%f) b(%f) c(%f)\n", v.x, v.y, delta, a, b, c);
					if (v.x < v.y)
						res = v.x;
					else
						res = v.y;
				}
				else
				{
					if (v.x > (double)0)
						res = v.x;
					if (v.y > (double)0)
						res = v.y;
				}
			}
			if (delta < 0.001 && delta > -0.001)
				res = v.z;
			if (vect_dot(vect_sub(vect_mult(rd, res), po), vect_mult(pn, -1)) > 0)
			{
				if (size.y != 0)
				{
					if (vect_dot(vect_sub(vect_mult(rd, res), po), pn) < size.y)
						return (res);
				}
				else
					return (res);
			}
		}
	}
	return (0);
}