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

t_mat4		add_zrotate(float angle)
{
	t_mat4 old;

	angle = angl(angle);
	old = get_mat4();
	old.a[0] = cos(angle);
	old.a[1] = -1 * (sin(angle));
	old.b[0] = sin(angle);
	old.b[1] = cos(angle);
	old.c[2] = 1;
	return (old);
}

t_mat4		add_xrotate(float angle)
{
	t_mat4 old;

	angle = angl(angle);
	old = get_mat4();
	old.a[0] = 1;
	old.b[1] = cos(angle);
	old.b[2] = -1 * (sin(angle));
	old.c[1] = sin(angle);
	old.c[2] = cos(angle);
	return (old);
}

t_mat4		add_yrotate(float angle)
{
	t_mat4 old;

	angle = angl(angle);
	old = get_mat4();
	old.a[0] = cos(angle);
	old.a[2] = sin(angle);
	old.b[1] = 1;
	old.c[0] = -1 * sin(angle);
	old.c[2] = cos(angle);
	return (old);
}
