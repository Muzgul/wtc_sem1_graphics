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
		node->size = vect_get(ft_atoi(ex[2]), 0, 0);
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
	t_vector	in;
	int			ex_check;

	ex_check = check_ex(ex);
	v = vect_get(0, 1, 0);
	if (ex_check == 5)
	{
		if ((in.x = ft_atoi(ex[2])) != 0)
			m = add_xrotate(in.x);
		if ((in.y = ft_atoi(ex[3])) != 0)
			m = add_yrotate(in.y);
		if ((in.z = ft_atoi(ex[4])) != 0)
			m = add_zrotate(in.z);
		if (in.x != 0 || in.y != 0 || in.z != 0)
			v = apply_mat(v, m);
	}
	free_arrstr(ex);
	if (ft_strcmp(node->type, "Cone") == 0)
		v = vect_mult(v, -1);
	if (ex_check != 3 && ex_check != 5)
		return (-1);
	node->n = v;
	return (0);
}
