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

t_vector		get_vector(float x, float y, float z, t_bool isnull)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = 1;
	new.null = isnull;
	return (new);
}

t_vector		get_applied(t_vector v, t_mat4 m)
{
	t_vector	applied;

	applied.x = v.x * m.a[0] + v.y * m.a[1] + v.z * m.a[2] + v.w * m.a[3];
	applied.y = v.x * m.b[0] + v.y * m.b[1] + v.z * m.b[2] + v.w * m.b[3];
	applied.z = v.x * m.c[0] + v.y * m.c[1] + v.z * m.c[2] + v.w * m.c[3];
	applied.w = v.x * m.d[0] + v.y * m.d[1] + v.z * m.d[2] + v.w * m.d[3];
	applied.null = FALSE;
	return (applied);
}
