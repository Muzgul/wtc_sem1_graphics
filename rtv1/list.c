/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:02:17 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/24 11:02:19 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		add_node(t_object **head, t_object *new)
{
	if (new != NULL)
	{
		new->next = *head;
		*head = new;
	}
}

t_object	*new_node(void)
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
