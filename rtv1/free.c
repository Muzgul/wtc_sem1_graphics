/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:33:18 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/01 11:33:20 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_arrstr(char **arr)
{
	int i;

	i = 0;
	if (*arr == NULL || arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_list(t_object **head)
{
	if (*head != NULL)
	{
		free_list(&(*head)->next);
		free(*head);
		*head = NULL;
	}
}
