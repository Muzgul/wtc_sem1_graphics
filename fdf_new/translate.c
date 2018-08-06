/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:09:45 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 13:09:46 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		apply_transform(ft_vector **grid, ft_vector (*f)(ft_vector, float), float value)
{
	int i;
	int j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j].null == 0)
		{
			grid[i][j] = (*f)(grid[i][j], value);
			j++;
		}
		i++;
	}
}

ft_vector	matrix_vector(ft_vector v, ft_mat4 m)
{
	// v.x = v.x * m.a[0] + v.y * m.a[1] + v.z * m.a[2] + v.w * m.a[3];
	// v.y = v.x * m.b[0] + v.y * m.b[1] + v.z * m.b[2] + v.w * m.b[3];
	// v.z = v.x * m.c[0] + v.y * m.c[1] + v.z * m.c[2] + v.w * m.c[3];
	// v.w = v.x * m.d[0] + v.y * m.d[1] + v.z * m.d[2] + v.w * m.d[3];
	v.x = v.x * m.a[0] + v.y * m.b[0] + v.z * m.c[0] + v.w * m.d[0];
	v.y = v.x * m.a[1] + v.y * m.b[1] + v.z * m.c[1] + v.w * m.d[1];
	v.z = v.x * m.a[2] + v.y * m.b[2] + v.z * m.c[2] + v.w * m.d[2];
	v.w = v.x * m.a[3] + v.y * m.b[3] + v.z * m.c[3] + v.w * m.d[3];
	return (v);
}

void		apply_matrix(ft_vector **grid, ft_mat4 m)
{
	int i;
	int j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j].null == 0)
		{
			grid[i][j] = matrix_vector(grid[i][j], m);
			j++;
		}
		i++;
	}
}
