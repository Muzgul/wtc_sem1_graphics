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

#include "rtv1.h"

t_mat4			mat_combine(t_mat4 old, t_mat4 new)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (old.a[i] != (double)0 && new.a[i] != (double)0)
			old.a[i] *= new.a[i];
		else
			old.a[i] += new.a[i];
		if (old.b[i] != (double)0 && new.b[i] != (double)0)
			old.b[i] *= new.b[i];
		else
			old.b[i] += new.b[i];
		if (old.c[i] != (double)0 && new.c[i] != (double)0)
			old.c[i] *= new.c[i];
		else
			old.c[i] += new.c[i];
		i++;
	}
	return (old);
}

t_vector		add_zrotate(t_vector old, float angle)
{
	t_mat4		new;

	angle = angl(angle);
	new = get_mat4();
	new.a[0] = cos(angle);
	new.a[1] = -1 * (sin(angle));
	new.b[0] = sin(angle);
	new.b[1] = cos(angle);
	new.c[2] = 1;
	return (apply_mat(old, new));
}

t_vector		add_xrotate(t_vector old, float angle)
{
	t_mat4		new;

	angle = angl(angle);
	new = get_mat4();
	new.a[0] = 1;
	new.b[1] = cos(angle);
	new.b[2] = -1 * (sin(angle));
	new.c[1] = sin(angle);
	new.c[2] = cos(angle);
	return (apply_mat(old, new));
}

t_vector		add_yrotate(t_vector old, float angle)
{
	t_mat4		new;

	angle = angl(angle);
	new = get_mat4();
	new.a[0] = cos(angle);
	new.a[2] = sin(angle);
	new.b[1] = 1;
	new.c[0] = -1 * sin(angle);
	new.c[2] = cos(angle);
	return (apply_mat(old, new));
}
