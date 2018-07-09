/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:57:01 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 15:57:02 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_color(int z_value)
{
	if (z_value < 0)
		z_value *= -1;
	if (z_value % 13 == 0)
		return (16101441);
	if (z_value % 11 == 0)
		return (4567965);
	if (z_value % 7 == 0)
		return (6139362);
	if (z_value % 5 == 0)
		return (10840509);
	if (z_value % 3 == 0)
		return (15495267);
	if (z_value % 2 == 0)
		return (9935514);
	return (16777215);
}

void		draw_vector(ft_vector v, void *mlx_ptr, void *mlx_win)
{
	mlx_pixel_put(mlx_ptr, mlx_win, v.x + 500, v.y + 500, v.c);
}
