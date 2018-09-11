/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:50:02 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/16 14:50:05 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	free_arr(void **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	if (arr != NULL)
		free(arr);
}

void	free_grid(t_grid g)
{
	int i;

	i = 0;
	while (i < g.h)
	{
		free(g.grid[i]);
		i++;
	}
	free(g.grid);
}
