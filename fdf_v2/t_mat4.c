/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mat4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:36:53 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/04 12:36:54 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ft_mat4     add_zrotate(float angle)
{
    ft_mat4 old;

    old = get_mat4();
    old.a[0] = cos(angle);
    old.a[1] = -1 * (sin(angle));
    old.b[0] = sin(angle);
    old.b[1] = cos(angle);
    old.c[2] = 1;
    old.d[3] = 1;
    return (old);
}

ft_mat4     add_xrotate(float angle)
{
    ft_mat4 old;

    old = get_mat4();
    old.a[0] = 1;
    old.b[1] = cos(angle);
    old.b[2] = -1 * (sin(angle));
    old.c[1] = sin(angle);
    old.c[2] = cos(angle);
    old.d[3] = 1;
    return (old);
}

ft_mat4     add_yrotate(float angle)
{
    ft_mat4 old;

    old = get_mat4();
    old.a[0] = cos(angle);
    old.a[2] = sin(angle);
    old.b[1] = 1;
    old.c[0] = -1 * sin(angle);
    old.c[2] = cos(angle);
    old.d[3] = 1;
    return (old);
}
