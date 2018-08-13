/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:51:19 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/04 12:51:20 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*point_grid_row(char *line, int row)
{
	t_point		*arr;
	char		**explode;
	int			cols;
	int			i;

	explode = ft_strsplit(line, ' ');
	cols = row_count((void *)explode);
	arr = (t_point *)malloc(sizeof(t_point) * (cols + 1));
	i = 0;
	while (i < cols)
	{
		arr[i].og = get_vector(i, row, ft_atoi(explode[i]), 0);
		arr[i].colour = get_color(ft_atoi(explode[i]));
		ft_strdel(&explode[i]);
		i++;
	}
	free(explode);
	arr[i].og = get_vector(0, 0, 0, 1);
	return (arr);
}

t_point		**point_grid(char **str_arr)
{
	t_point		**grid;
	int			rows;
	int			i;

	rows = row_count((void **)str_arr);
	grid = (t_point **)malloc(sizeof(t_point *) * (rows + 1));
	i = 0;
	while (i < rows)
	{
		grid[i] = point_grid_row(str_arr[i], i);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
