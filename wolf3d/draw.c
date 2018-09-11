/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 12:22:48 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/24 12:22:49 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	add_pixel(t_mlx_img mlx_img, int x, int y, int color)
{
	int	pos;

	pos = y * mlx_img.size_l;
	pos += x * (mlx_img.bpp / 8);
	mlx_img.img[pos] = ((color / 1000000) % 1000) - 128;
	mlx_img.img[pos + 1] = ((color / 1000) % 1000) - 128;
	mlx_img.img[pos + 2] = color % 1000;
	mlx_img.img[pos + 3] = 1;
}

void	search_and_draw(t_grid g, t_cam c, t_mlx_obj o)
{
	int i;

	o.mlx_img.mlx_img = mlx_new_image(o.mlx_ptr, o.width, o.height);
	o.mlx_img.img = mlx_get_data_addr(o.mlx_img.mlx_img, &o.mlx_img.bpp,
		&o.mlx_img.size_l, &o.mlx_img.e);
	i = 0;
	while (i < o.width)
	{
		search_to(o, c, g, i);
		i++;
	}
	mlx_clear_window(o.mlx_ptr, o.mlx_win);
	mlx_put_image_to_window(o.mlx_ptr, o.mlx_win, o.mlx_img.mlx_img, 0, 0);
	mlx_destroy_image(o.mlx_ptr, o.mlx_img.mlx_img);
}

void	draw_col_calc(float dist, int *height, int *to_skip, t_mlx_obj o)
{
	if (dist == (float)0 || dist == (float)-0)
	{
		*height = 0;
		*to_skip = 0;
	}
	else
	{
		*height = o.height / dist;
		if (*height > (float)o.height)
			*height = o.height;
		*to_skip = o.height - *height;
		*to_skip /= 2;
	}
}

void	draw_col(t_mlx_obj o, int col, float dist, int side)
{
	int		height;
	int		to_skip;
	int		i;

	draw_col_calc(dist, &height, &to_skip, o);
	i = 0;
	while (i < o.height)
	{
		if (i >= to_skip && i <= height + to_skip)
		{
			if (side == 0)
				add_pixel(o.mlx_img, col, i, 49035030);
			if (side == 1)
				add_pixel(o.mlx_img, col, i, 90058049);
		}
		else
		{
			if (i < o.height / 2)
				add_pixel(o.mlx_img, col, i, 255255);
			else
				add_pixel(o.mlx_img, col, i, 1281128000);
		}
		i++;
	}
}
