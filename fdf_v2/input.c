/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:18:27 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 10:18:28 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     row_count(void  **array)
{
	int i;

	if (array == NULL || *array == NULL)
		return (0);
	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int		vcol_count(ft_point **array)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j].og.null == 0)
		{
			if (j > len)
				len = j;
			j++;
		}
		i++;
	}
	return (len);
}

//Take current row count, add1, free input array and return new one;
char    **add_to_array(char **array, char *row)
{
	int i;
	int array_length;
	char **new_array;

	array_length = row_count((void **)array);
	new_array = (char **)malloc(sizeof(char *) * (array_length + 2));//Add one for new row and one for NULL placeholder
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

char    **read_to_array(int fd)
{
	char    *line;
	char    **raw_data;

	line = NULL;
	raw_data = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		raw_data = add_to_array(raw_data, line);
	}
	return (raw_data);
}

int     split_and_count(char *line, char c)
{
    int i;
    char **temp;

    temp = ft_strsplit(line, c);
    i = row_count((void **)temp);
    free(temp);
    return (i);
}
