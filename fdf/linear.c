/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:42:00 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 11:42:02 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_y(t_point **grid, float diff)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j].og.null == 0)
		{
			grid[i][j].og.y += diff;
			j++;
		}
		i++;
	}
}

void	shift_z(t_point **grid, float diff)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j].og.null == 0)
		{
			grid[i][j].og.z += diff;
			j++;
		}
		i++;
	}
}

void	shift_x(t_point **grid, float diff)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j].og.null == 0)
		{
			grid[i][j].og.x += diff;
			j++;
		}
		i++;
	}
}
