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

t_object	*new_node()
{
	t_object	*n;

	n = (t_object *)malloc(sizeof(t_object));
	n->type = NULL;
	n->colour = 0;
	n->size = vect_get(0, 0, 0);
	n->origin = vect_get(0, 0, 0);
	n->n = vect_get(0, 0, 0);
	n->next = NULL;
	return (n);
}

void		add_node(t_object **head, t_object *new)
{
	if (new != NULL)
	{
		new->next = *head;
		*head = new;
	}
}

int			read_node(t_object **head, char *line)
{
	char **ex;

	ex = NULL;
	if (ft_strncmp(line, "***", 3) == 0)
	{
		add_node(head, new_node());
		return (0);
	}
	else
	{
		ex = ft_strsplit(line, ' ');
		if (ex[0][0] == '-')
		{
			if (ft_strcmp(ex[1], "Origin:") == 0)
				return (fetch_origin(*head, ex));
			if (ft_strcmp(ex[1], "Size:") == 0)
				return (fetch_size(*head, ex));
			if (ft_strcmp(ex[1], "Rotation:") == 0)
				return (fetch_norm(*head, ex));
			if (ft_strcmp(ex[1], "Colour:") == 0 || ft_strcmp(ex[1], "Color") == 0)
				return (fetch_colour(*head, ex));
		}
		else
			return (fetch_name(*head, line));
	}
	return (-1);
}

t_object	*read_objects(int fd)
{
	t_object 	*head;
	char		*line;
	int			res;

	head = NULL;
	line = NULL;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (read_node(&head, line) < 0)
		{
			ft_putendl("[ ERROR ]: Error in config file!");
			free(line);
			free_list(&head);
			return (NULL);
		}
		free(line);
	}
	return (head);
}
