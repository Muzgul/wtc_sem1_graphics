/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:16:49 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/24 11:16:50 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    input_error(t_object **head, char **ex, char *msg)
{
	if (ex != NULL)
		free_arrstr(ex);
	if (head != NULL && *head != NULL)
		free_list(head);
	ft_putstr("[ Error! ]: ");
	ft_putendl(msg);
	exit(0);
}
