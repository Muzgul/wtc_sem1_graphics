/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:06:31 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/04 12:06:32 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ft_mat4     get_mat4()
{
	ft_mat4 new;
	int     i;

	i = 0;
	while (i < 4)
	{
		new.a[i] = 0;
		new.b[i] = 0;
		new.c[i] = 0;
		new.d[i] = 0;
		i++;
	}
	return (new);
}

ft_mat4     mult_mat4(ft_mat4 f, ft_mat4 s) // might be the wrong way round
{
	ft_mat4     res;
	int         i;

	i = 0;
	while (i < 4)
	{
		res.a[i] = f.a[0] * s.a[i] + f.a[1] * s.b[i] + f.a[2] * s.c[i] + f.a[3] * s.d[i];
		res.b[i] = f.b[0] * s.a[i] + f.b[1] * s.b[i] + f.b[2] * s.c[i] + f.b[3] * s.d[i];
		res.c[i] = f.c[0] * s.a[i] + f.c[1] * s.b[i] + f.c[2] * s.c[i] + f.c[3] * s.d[i];
		res.d[i] = f.d[0] * s.a[i] + f.d[1] * s.b[i] + f.d[2] * s.c[i] + f.d[3] * s.d[i];
		// res.a[i] = f.a[i] * s.a[0] + f.a[i] * s.b[1] + f.a[i] * s.c[2] + f.a[i] * s.d[3];
		// res.b[i] = f.b[i] * s.a[0] + f.b[i] * s.b[1] + f.b[i] * s.c[2] + f.b[i] * s.d[3];
		// res.c[i] = f.c[i] * s.a[0] + f.c[i] * s.b[1] + f.c[i] * s.c[2] + f.c[i] * s.d[3];
		// res.d[i] = f.d[i] * s.a[0] + f.d[i] * s.b[1] + f.d[i] * s.c[2] + f.d[i] * s.d[3];
		i++;
	}
	return (res);
}

ft_vector	apply_mat(ft_vector og, ft_mat4 m)
{
	float x;
	float y;
	float z;
	float w;

	// v.x = v.x * m.a[0] + v.y * m.a[1] + v.z * m.a[2] + v.w * m.a[3];
	// v.y = v.x * m.b[0] + v.y * m.b[1] + v.z * m.b[2] + v.w * m.b[3];
	// v.z = v.x * m.c[0] + v.y * m.c[1] + v.z * m.c[2] + v.w * m.c[3];
	// v.w = v.x * m.d[0] + v.y * m.d[1] + v.z * m.d[2] + v.w * m.d[3];
	x = og.x * m.a[0] + og.y * m.b[0] + og.z * m.c[0] + og.w * m.d[0];
	y = og.x * m.a[1] + og.y * m.b[1] + og.z * m.c[1] + og.w * m.d[1];
	z = og.x * m.a[2] + og.y * m.b[2] + og.z * m.c[2] + og.w * m.d[2];
	w = og.x * m.a[3] + og.y * m.b[3] + og.z * m.c[3] + og.w * m.d[3];
	return (get_vector(x, y, z, false));
}
