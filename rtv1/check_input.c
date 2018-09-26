/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:59:25 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/24 11:59:26 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	check_name(char *line)
{
	if (ft_strcmp(line, "Camera") == 0)
		return (1);
	if (ft_strcmp(line, "Light") == 0)
		return (1);
	if (ft_strcmp(line, "Sphere") == 0)
		return (1);
	if (ft_strcmp(line, "Plane") == 0)
		return (1);
	if (ft_strcmp(line, "Cylinder") == 0)
		return (1);
	if (ft_strcmp(line, "Cone") == 0)
		return (1);
	return (-1);
}
