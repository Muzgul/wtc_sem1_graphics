/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fetch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:32:12 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/01 11:32:13 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			check_ex(char **ex)
{
	int i;

	if (ex == NULL)
		return (-1);
	i = 0;
	while (ex[i] != NULL)
		i++;
	return (i);
}

int			fetch_name(t_object *node, char *line)
{

	if (line == NULL || node->type != NULL)
		return (-1);
	node->type = ft_strdup(line);
	return (0);
}

int			fetch_origin(t_object *node, char **ex)
{
	int ex_check;

	ex_check = check_ex(ex);
	if (ex_check == 3)
		node->origin = vect_get(ft_atoi(ex[2]), ft_atoi(ex[2]), ft_atoi(ex[2]));
	if (ex_check == 5)
		node->origin = vect_get(ft_atoi(ex[2]), ft_atoi(ex[3]), ft_atoi(ex[4]));
	free_arrstr(ex);
	if (ex_check != 3 && ex_check != 5)		
		return (-1);
	return (0);
}

int			fetch_size(t_object *node, char **ex)
{
	int ex_check;

	ex_check = check_ex(ex);
	if (ex_check == 3)
		node->size = vect_get(ft_atoi(ex[2]), ft_atoi(ex[2]), ft_atoi(ex[2]));
	if (ex_check == 5)
		node->size = vect_get(ft_atoi(ex[2]), ft_atoi(ex[3]), ft_atoi(ex[4]));
	free_arrstr(ex);
	if (ex_check != 3 && ex_check != 5)		
		return (-1);
	return (0);
}

int			fetch_colour(t_object *node, char **ex)
{
	int			ex_check;
	t_vector	colour;

	ex_check = check_ex(ex);
	if (ex_check == 3)
	{
		if (ft_strcmp(ex[2], "white") == 0 || ft_strcmp(ex[2], "White") == 0)
			colour = vect_get(255, 255, 255);
		if (ft_strcmp(ex[2], "red") == 0 || ft_strcmp(ex[2], "Red") == 0)
			colour = vect_get(255, 0, 0);
		if (ft_strcmp(ex[2], "green") == 0 || ft_strcmp(ex[2], "Green") == 0)
			colour = vect_get(0, 255, 0);
		if (ft_strcmp(ex[2], "blue") == 0 || ft_strcmp(ex[2], "Blue") == 0)
			colour = vect_get(0, 0, 255);
	}
	if (ex_check == 5)
		colour = vect_get(ft_atoi(ex[2]), ft_atoi(ex[3]), ft_atoi(ex[4]));
	node->colour = colour.x * 65536 + colour.y * 256 + colour.z;
	free_arrstr(ex);
	if (ex_check != 3 && ex_check != 5)
		return (-1);
	return (0);
}

int			fetch_norm(t_object *node, char **ex)
{
	t_mat4		m;
	t_vector	v;
	int			ex_check;

	ex_check = check_ex(ex);
	v = vect_get(0, 1, 0);
	if (ex_check == 5)
	{
		m = get_mat4();
		if (ft_atoi(ex[2]) != 0)
			m = add_xrotate(ft_atoi(ex[2]));
		if (ft_atoi(ex[3]) != 0)
			m = add_yrotate(ft_atoi(ex[3]));
		if (ft_atoi(ex[4]) != 0)
			m = add_zrotate(ft_atoi(ex[4]));
		v = apply_mat(v, m);
	}
	free_arrstr(ex);
	if (ex_check == 3 || ex_check == 5)
		node->n = v;
	else
		return (-1);
	return (0);
}