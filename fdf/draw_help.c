/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:17:43 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/10 13:17:45 by mmacdona         ###   ########.fr       */
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

void		add_pixel(t_mlx_img img, int x, int y, int color)
{
	int		pos;

	pos = y * img.size_l;
	pos += x * (img.bpp / 8);
	img.line[pos] = ((color / 1000000) % 1000) - 128;
	img.line[pos + 1] = ((color / 1000) % 1000) - 128;
	img.line[pos + 2] = color % 1000;
	img.line[pos + 3] = 1;
}

int			in_bounds(t_vector v, int width, int height)
{
	if (v.x > 0 && v.x < width && v.y > 0 && v.y < height)
		return (1);
	return (0);
}

void		draw_point(t_mlx_obj *o, int i, int j, t_mlx_img mlx_img)
{
	if (in_bounds(o->grid[i][j].calc, o->width, o->height) > 0)
	{
		add_pixel(mlx_img, o->grid[i][j].calc.x,
					o->grid[i][j].calc.y, o->grid[i][j].colour);
		if (i > 0 && in_bounds(o->grid[i][j].calc, o->width, o->height) > 0 &&
			in_bounds(o->grid[i - 1][j].calc, o->width, o->height) > 0)
			draw_line(o->grid[i - 1][j], o->grid[i][j], mlx_img);
		if (j > 0 && in_bounds(o->grid[i][j].calc, o->width, o->height) > 0 &&
			in_bounds(o->grid[i][j - 1].calc, o->width, o->height) > 0)
			draw_line(o->grid[i][j], o->grid[i][j - 1], mlx_img);
	}
}
