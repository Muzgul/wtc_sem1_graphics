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

#include "rtv1.h"

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
					+ f.a[2] * s.c[i] + f.a[3];
		res.b[i] = f.b[0] * s.a[i] + f.b[1] * s.b[i]
					+ f.b[2] * s.c[i] + f.b[3];
		res.c[i] = f.c[0] * s.a[i] + f.c[1] * s.b[i]
					+ f.c[2] * s.c[i] + f.c[3];
		i++;
	}
	return (res);
}

t_vector	apply_mat(t_vector og, t_mat4 m)
{
	t_vector v;

	v.x = og.x * m.a[0] + og.y * m.b[0] + og.z * m.c[0];
	v.y = og.x * m.a[1] + og.y * m.b[1] + og.z * m.c[1];
	v.z = og.x * m.a[2] + og.y * m.b[2] + og.z * m.c[2];
	return (v);
}
