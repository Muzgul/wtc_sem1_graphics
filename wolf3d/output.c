/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:57:46 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/15 15:57:47 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_strarr(char **strarr)
{
	int i;

	i = 0;
	while (strarr[i] != NULL)
	{
		ft_putendl(strarr[i]);
		i++;
	}
}
