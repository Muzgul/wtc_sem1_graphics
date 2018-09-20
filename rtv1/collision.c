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
        if ((res = test_object(node, ro, rd)) > (double)0.0001)
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

double      shortest_dist_shadow(t_object *obj, t_vector ro, t_vector rd, double *colour)
{
    t_object    *node;
    double      res;
    double      shortest;

    shortest = -1;
    node = obj;
    while (node != NULL)
    {
        if ((res = test_object_shadow(node, ro, rd)) > (double)0.0001)
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
    res = shortest_dist_shadow(obj, ray, vect_norm(vect_sub(light.origin, ray)), &colour);
    // res = shortest_dist(obj, light.origin, vect_sub(ray, light.origin),  &colour);
    dist = (vect_get_dist(light.origin, vect_mult(vect_norm(ray), res)));
    // dist = (vect_get_dist(light.origin, vect_mult(ray, res)));
    // if (dist >= max)
    //     return (max);
    // // printf("d(%f) m(%f)\n", dist, max);
    // if (res <= (double)0.00001)
    // {
    //     // printf("d(%f) m(%f) dif(%f) res(%f)\n", dist, max, max - dist, res);
    //     return (-1);
    // }
    if (dist < max && res != 0)
    {
        // printf("d(%f) m(%f) dif(%f) res(%f)\n", dist, max, max - dist, res);
        return (0);
        // return (max * (1 + (dist / max)));
    }
    return (max);
}