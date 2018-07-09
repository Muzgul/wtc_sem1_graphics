/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:25:09 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 10:25:10 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ft_vector   new_vector(float x, float y, float z, int null)
{
    ft_vector   new;

    new.x = x;
    new.y = y;
    new.z = z;
	new.c = get_color(z);
	new.null = null;
    return (new);
}

ft_vector	*vector_grid_row(char *line, int row)
{
	ft_vector	*arr;
	char		**explode;
	int			cols;
	int			i;

	explode = ft_strsplit(line, ' ');
	cols = row_count((void *)explode);
	arr = (ft_vector *)malloc(sizeof(ft_vector) * (cols + 1));
	i = 0;
	while (i < cols)
	{
		arr[i] = new_vector(i, row, ft_atoi(explode[i]), 0);
		ft_strdel(&explode[i]);
		i++;
	}
	free(explode);
	arr[i] = new_vector(0, 0, 0, 1);
	return (arr);
}

ft_vector   **vector_grid(char **str_arr)
{
    ft_vector	**grid;
    int			rows;
	int			i;

	rows = row_count((void **)str_arr);
    grid = (ft_vector **)malloc(sizeof(ft_vector *) * (rows + 1));
	i = 0;
	while (i < rows)
	{
		grid[i] = vector_grid_row(str_arr[i], i);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
