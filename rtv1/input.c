/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 14:51:31 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/31 14:51:32 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			read_cam(int fd, t_cam *c)
{
	char	*line;
	char	**ex;
	int		ex_check;

	if (get_next_line(fd, &line) <= 0)
		return (-1);
	ex = ft_strsplit(line, ';');
	free(line);
	if ((ex_check = check_ex(ex)) != 3)
		input_error(NULL, ex, "Invalid argument for camera!");
	if (fetch_vect(ex[1], &c->pos) < 3)
		input_error(NULL, ex, "Invalid camera origin!");
	if (fetch_vect(ex[2], &c->dir) < 3 ||
		fabs(c->dir.x) + fabs(c->dir.y) + fabs(c->dir.z) != 1)
		input_error(NULL, ex, "Invalid camera direction!");
	free_arrstr(ex);
	return (0);
}

int			read_light(int fd, t_light *light, t_cam c)
{
	char		*line;
	char		**ex;
	t_vector	v;

	if (get_next_line(fd, &line) <= 0)
		return (-1);
	ex = ft_strsplit(line, ';');
	free(line);
	if (check_ex(ex) != 3)
		input_error(NULL, ex, "Invalid light!");
	if (fetch_vect(ex[1], &light->pos) < 1)
		input_error(NULL, ex, "Invalid light!");
	if (fetch_vect(ex[2], &v) != 1)
		input_error(NULL, ex, "Invalid light brightness!");
	light->brightness = v.x;
	light->pos = vect_sub(light->pos, c.pos);
	free_arrstr(ex);
	return (0);
}

int			read_nodes(int fd, t_object **head, t_cam c)
{
	char		*line;
	char		**ex;

	*head = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ex = ft_strsplit(line, ';');
		free(line);
		if (check_ex(ex) != 5)
			input_error(NULL, ex, "Invalid argument for node!");
		add_node(head, new_node());
		fetch_name(ex, head);
		fetch_origin(ex, head, c);
		fetch_norm(ex, head);
		fetch_size(ex, head);
		fetch_colour(ex, head);
		free_arrstr(ex);
	}
	if (*head != NULL)
		return (0);
	return (-1);
}

t_object	*read_file(int fd, t_light *light, t_cam *c)
{
	t_object *head;

	head = NULL;
	if (read_cam(fd, c) == -1)
		input_error(&head, NULL, "Camera info not at top!");
	if (read_light(fd, light, *c) == -1)
		input_error(&head, NULL, "Light must be at 2nd position!");
	if (read_nodes(fd, &head, *c) == -1)
		input_error(&head, NULL, "Invalid arguments!");
	c->pos = vect_get(0, 0, 0);
	return (head);
}
