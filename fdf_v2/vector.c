/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:56:15 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/04 11:56:17 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ft_vector       get_vector(float x, float y, float z, ft_bool isnull)
{
    ft_vector   new;

    new.x = x;
    new.y = y;
    new.z = z;
    new.w = 1;
    new.null = isnull;
    return (new);
}

ft_vector       get_applied(ft_vector v, ft_mat4 m)
{
    ft_vector applied;

    applied.x = v.x * m.a[0] + v.y * m.a[1] + v.z * m.a[2] + v.w * m.a[3];
    applied.y = v.x * m.b[0] + v.y * m.b[1] + v.z * m.b[2] + v.w * m.b[3];
    applied.z = v.x * m.c[0] + v.y * m.c[1] + v.z * m.c[2] + v.w * m.c[3];
    applied.w = v.x * m.d[0] + v.y * m.d[1] + v.z * m.d[2] + v.w * m.d[3];
    applied.null = false;
    return (applied);
}

void		draw_vector(ft_point v, void *mlx_ptr, void *mlx_win)
{
	mlx_pixel_put(mlx_ptr, mlx_win, v.calc.x, v.calc.y, v.colour);
}
