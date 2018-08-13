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
    // n.z = v.z * size;
    n.z = v.z;
    n.c = v.c;
    n.null = v.null;
    return (n);
}

ft_vector   for_vector(ft_vector v)
{
    v.x /= v.w;
    v.y /= v.w;
    v.z /= v.w;
    // v.x /= -1 * v.z;
    // v.y /= -1 * v.z;
    // v.z /= -1 * v.z;
    // v.x = (1 + v.x)/2;
    // v.y = (1 + v.y)/2;
    // v.x *= 1600;
    // v.y *= 900;
    return (v);
}

void    apply_perspective(ft_vector **grid)
{
    int i;
    int j;

    i = 0;
    while (grid[i] != NULL)
    {
        j = 0;
        while (grid[i][j].null == 0)
        {
            grid[i][j] = for_vector(grid[i][j]);
            j++;
        }
        i++;
    }    
}
