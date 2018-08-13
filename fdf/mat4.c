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

t_mat4		get_mat4(void)
{
	t_mat4	new;
	int		i;

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

t_mat4		mult_mat4(t_mat4 f, t_mat4 s)
{
	t_mat4	res;
	int		i;

	i = 0;
	while (i < 4)
	{
		res.a[i] = f.a[0] * s.a[i] + f.a[1] * s.b[i]
					+ f.a[2] * s.c[i] + f.a[3] * s.d[i];
		res.b[i] = f.b[0] * s.a[i] + f.b[1] * s.b[i]
					+ f.b[2] * s.c[i] + f.b[3] * s.d[i];
		res.c[i] = f.c[0] * s.a[i] + f.c[1] * s.b[i]
					+ f.c[2] * s.c[i] + f.c[3] * s.d[i];
		res.d[i] = f.d[0] * s.a[i] + f.d[1] * s.b[i]
					+ f.d[2] * s.c[i] + f.d[3] * s.d[i];
		i++;
	}
	return (res);
}

t_vector	apply_mat(t_vector og, t_mat4 m)
{
	float x;
	float y;
	float z;
	float w;

	x = og.x * m.a[0] + og.y * m.b[0] + og.z * m.c[0] + og.w * m.d[0];
	y = og.x * m.a[1] + og.y * m.b[1] + og.z * m.c[1] + og.w * m.d[1];
	z = og.x * m.a[2] + og.y * m.b[2] + og.z * m.c[2] + og.w * m.d[2];
	w = og.x * m.a[3] + og.y * m.b[3] + og.z * m.c[3] + og.w * m.d[3];
	return (get_vector(x, y, z, FALSE));
}
