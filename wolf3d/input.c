/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:57:35 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/15 15:57:36 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	**add_to_array(char **array, char *row)
{
	int		i;
	int		array_length;
	char	**new_array;

	array_length = row_count((void **)array);
	new_array = (char **)malloc(sizeof(char *) * (array_length + 2));
	i = 0;
	while (i < array_length)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = row;
	new_array[i + 1] = NULL;
	free(array);
	return (new_array);
}

char	**read_to_array(int fd)
{
	char	*line;
	char	**raw_data;

	line = NULL;
	raw_data = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		raw_data = add_to_array(raw_data, line);
	}
	return (raw_data);
}

int		**convert_to_int(char **strarr)
{
	int		**grid;
	char	**explode;
	int		i;
	int		j;

	grid = (int **)malloc(sizeof(int *) * (row_count((void **)strarr)));
	i = 0;
	while (strarr[i] != NULL)
	{
		explode = ft_strsplit(strarr[i], ' ');
		grid[i] = (int *)malloc(sizeof(int) * (row_count((void **)explode)));
		j = 0;
		while (explode[j] != NULL)
		{
			grid[i][j] = ft_atoi(explode[j]);
			j++;
		}
		free_arr((void **)explode);
		i++;
	}
	return (grid);
}

int		row_count(void **array)
{
	int i;

	if (array == NULL || *array == NULL)
		return (0);
	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}