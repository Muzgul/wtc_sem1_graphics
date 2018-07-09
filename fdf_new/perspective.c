/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:27:16 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 12:27:17 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ft_vector   to_negz(ft_vector v, float neg)
{
    ft_vector n;

    if (v.null == 1 || neg != -1)
        return (v);
    n.x = v.x / (-1 * v.z);
    n.y = v.y / (-1 * v.z);
    n.z = v.z / (-1 * v.z);
    n.c = v.c;
    n.null = v.null;
    return (n);
}

ft_vector   scale_by(ft_vector v, float size)
{
    ft_vector n;

    if (v.null == 1)
        return (v);
    n.x = v.x * size;
    n.y = v.y * size;
    n.z = v.z * size;
    n.c = v.c;
    n.null = v.null;
    return (n);
}
