/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 10:50:09 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/16 10:50:11 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ft_mat4     new_matrix()
{
    ft_mat4 temp;

	temp.a[0] = 0;
	temp.a[1] = 0;
	temp.a[2] = 0;
	temp.a[3] = 0;
	temp.b[0] = 0;
	temp.b[1] = 0;
	temp.b[2] = 0;
	temp.b[3] = 0;
	temp.c[0] = 0;
	temp.c[1] = 0;
	temp.c[2] = 0;
	temp.c[3] = 0;
	temp.d[0] = 0;
	temp.d[1] = 0;
	temp.d[2] = 0;
	temp.d[3] = 0;
    return (temp);
}

ft_mat4     add_perspective(ft_mat4 old, float near, float far, float fov, float aspect)
{
    fov /= 2;
    old.a[0] += 1/((aspect) * tan(fov));
	old.b[1] += 1/tan(fov);
	old.c[2] += (near + far)/(near - far);
	old.c[3] += (2 * near * far)/(near - far);
	old.d[2] += -1;
    return (old);
}

ft_mat4     add_zrotate(ft_mat4 old, float angle)
{
    old.a[0] += cos(angle);
    old.a[1] += -1 * (sin(angle));
    old.b[0] += sin(angle);
    old.b[1] += cos(angle);
    old.c[2] += 1;
    old.d[3] += 1;
    return (old);
}

ft_mat4     add_xrotate(ft_mat4 old, float angle)
{
    old.a[0] += 1;
    old.b[1] += cos(angle);
    old.b[2] += -1 * (sin(angle));
    old.c[1] += sin(angle);
    old.c[2] += cos(angle);
    old.d[3] += 1;
    return (old);
}

ft_mat4     add_yrotate(ft_mat4 old, float angle)
{
    old.a[0] += cos(angle);
    old.a[2] += sin(angle);
    old.b[1] += 1;
    old.c[0] += -1 * sin(angle);
    old.c[2] += cos(angle);
    old.d[3] += 1;
    return (old);
}

