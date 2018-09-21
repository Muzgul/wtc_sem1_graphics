/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:38:30 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/18 13:38:34 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	shortest_dist(t_object *obj, t_vector ro, t_vector rd, double *colour)
{
	t_object	*node;
	double		res;
	double		shortest;

	shortest = -1;
	node = obj;
	while (node != NULL)
	{
		if ((res = test_object(node, point_get(ro, rd))) > (double)0.0001)
		{
			if (shortest == -1 || res < shortest)
			{
				shortest = res;
				*colour = node->colour;
			}
		}
		node = node->next;
	}
	if (shortest == -1)
		return (0);
	return (shortest);
}

double	light_intensity(t_object *obj, t_vector light, t_vector ray)
{
	double	dist;
	double	res;
	double	max;
	double	colour;

	max = (vect_get_dist(light, ray));
	res = shortest_dist(obj, ray,
			vect_norm(vect_sub(light, ray)), &colour);
	dist = (vect_get_dist(light, vect_mult(vect_norm(ray), res)));
	if (dist < max && res != 0)
		return (0);
	return (max);
}

double	test_object(t_object *o, t_point r)
{
	if (ft_strcmp(o->type, "Sphere") == 0)
		return (test_circle(o->size.x, o->origin, r));
	if (ft_strcmp(o->type, "Plane") == 0)
		return (test_plane(point_get(o->origin, o->n), r));
	if (ft_strcmp(o->type, "Disk") == 0)
		return (test_disk(point_get(o->origin, o->n), r, o->size.x));
	if (ft_strcmp(o->type, "Cylinder") == 0)
		return (test_cylinder(point_get(o->origin, o->n), r, o->size));
	if (ft_strcmp(o->type, "Cone") == 0)
		return (test_cone(point_get(o->origin, o->n), r, o->size));
	return (-1);
}
