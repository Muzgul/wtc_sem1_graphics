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

int			fetch_name(char **ex, t_object **head)
{
	if (check_name(ex[0]) == -1)
		input_error(head, ex, "Invalid object!");
	(*head)->type = ft_strdup(ex[0]);
	return (0);
}

int			fetch_origin(char **ex, t_object **head, t_cam c)
{
	if (ft_strncmp(ex[1], "Origin", 6) != 0)
		input_error(head, ex, "Invalid property!");
	if (fetch_vect(ex[1], &(*head)->origin) < 3)
		input_error(head, ex, "Invalid origin!");
	(*head)->origin = vect_sub((*head)->origin, c.pos);
	return (0);
}

int			fetch_norm(char **ex, t_object **head)
{
	t_vector	m;

	if (ft_strncmp(ex[2], "Rotation", 8) != 0)
		input_error(head, ex, "Invalid property!");
	if (fetch_vect(ex[2], &(*head)->n) < 3)
		input_error(head, ex, "Invalid rotation!");
	m = vect_get(0, 1, 0);
	if ((*head)->n.z != 0)
		m = add_zrotate(m, (*head)->n.z);
	if ((*head)->n.x != 0)
		m = add_xrotate(m, (*head)->n.x);
	if ((*head)->n.y != 0)
		m = add_yrotate(m, (*head)->n.y);
	if (ft_strcmp((*head)->type, "Cone") == 0)
		m = vect_mult(m, -1);
	(*head)->n = m;
	return (0);
}

int			fetch_size(char **ex, t_object **head)
{
	if (ft_strncmp(ex[3], "Size", 4) != 0)
		input_error(head, ex, "Invalid property!");
	if (fetch_vect(ex[3], &(*head)->size) < 1)
		input_error(head, ex, "Invalid size!");
	return (0);
}

int			fetch_colour(char **ex, t_object **head)
{
	char		**val;
	t_vector	colour;

	if (ft_strncmp(ex[4], "Colour", 6) != 0)
		input_error(head, ex, "Invalid property!");
	val = ft_strsplit(ex[4], '=');
	colour = vect_get(0, 0, 0);
	if (check_ex(val) != 2)
		input_error(head, ex, "Invalid colour!");
	if (ft_strcmp(val[1], "white") == 0 || ft_strcmp(val[1], "White") == 0)
		colour = vect_get(255, 255, 255);
	if (ft_strcmp(val[1], "red") == 0 || ft_strcmp(val[1], "Red") == 0)
		colour = vect_get(255, 0, 0);
	if (ft_strcmp(val[1], "green") == 0 || ft_strcmp(val[1], "Green") == 0)
		colour = vect_get(0, 255, 0);
	if (ft_strcmp(val[1], "blue") == 0 || ft_strcmp(val[1], "Blue") == 0)
		colour = vect_get(0, 0, 255);
	(*head)->colour = colour.x * 65536 + colour.y * 256 + colour.z;
	if ((*head)->colour == 0)
		input_error(head, ex, "Invalid colour!");
	return (0);
}
