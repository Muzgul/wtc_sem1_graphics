/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:11:15 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/01 14:11:17 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		print_vector(t_vector v)
{
	ft_putstr("V x10: ");
	ft_putnbr(v.x * 10);
	ft_putstr(", ");
	ft_putnbr(v.y * 10);
	ft_putstr(", ");
	ft_putnbr(v.z * 10);
	ft_putstr("\n");
}

void		print_list(t_object *head)
{
	t_object *cur;

	cur = head;
	while (cur != NULL)
	{
		ft_putendl(cur->type);
		print_vector(cur->origin);
		ft_putstr("Size: ");
		print_vector(cur->size);
		ft_putchar('\n');
		ft_putstr("Colour: ");
		ft_putnbr(cur->colour);
		ft_putchar('\n');
		cur = cur->next;
	}
}
