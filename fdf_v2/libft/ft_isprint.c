/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:12:59 by mmacdona          #+#    #+#             */
/*   Updated: 2017/06/10 16:17:46 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	if (ft_isalnum(c) != 0)
		return (1);
	if (c >= 32 && c <= 39)
		return (1);
	if (c >= 40 && c <= 47)
		return (1);
	if ((c >= 58 && c <= 63) || c == 64)
		return (1);
	if ((c >= 91 && c <= 95) || c == 96)
		return (1);
	if (c >= 123 && c <= 126)
		return (1);
	return (0);
}
