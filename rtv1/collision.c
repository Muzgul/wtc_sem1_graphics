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

double      shortest_dist(t_object *obj, t_vector ro, t_vector rd, double *colour)
{
    t_object    *node;
    double      res;
    double      shortest;

    shortest = -1;
    node = obj;
    while (node != NULL)
    {
        if ((res = test_object(node, ro, rd)) > 0)
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

double      light_intensity(t_object *obj, t_object light, t_vector ray)
{
    double      dist;
    double      res;
    double      max;
    double      colour;

    max = (vect_get_dist(light.origin, ray));
    res = shortest_dist(obj, light.origin, vect_sub(ray, light.origin),  &colour);
    dist = (vect_get_dist(light.origin, vect_mult(ray, res)));
    if (max - dist < 1 && max - dist > -1)
        return (max);
    if (dist < max)
        return (max * (1 + (dist / max)));
    return (-1);
}