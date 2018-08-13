/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:40:40 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/09 14:40:42 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_strarr(char **strarr)
{
	int i;

	i = 0;
	while (strarr[i] != NULL)
	{
		free(strarr[i]);
		i++;
	}
}

void	free_grid(t_point **grid)
{
	int i;

	i = 0;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
}
