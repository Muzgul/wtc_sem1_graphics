/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:50:54 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/21 08:50:56 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vector	mat2_apply(t_vector v, t_mat2 m)
{
	t_vector n;

	n.x = v.x * m.a[0] + v.y * m.a[1];
	n.y = v.x * m.b[0] + v.y * m.b[1];
	return (n);
}

t_mat2		mat2_rotate(float angle)
{
	t_mat2	m;

	m.a[0] = cos(angle);
	m.a[1] = -1 * sin(angle);
	m.b[0] = sin(angle);
	m.b[1] = cos(angle);
	return (m);
}
