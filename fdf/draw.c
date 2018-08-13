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

int				draw_horiz(t_point v1, t_point v2, t_mlx_img mlx_img)
{
	float		x;
	float		y;
	int			dir;

	x = v1.calc.x;
	y = v1.calc.y;
	dir = -1;
	if (x < v2.calc.x)
		dir = 1;
	while ((int)x != (int)v2.calc.x)
	{
		add_pixel(mlx_img, x, y, (v1.colour + v2.colour) / 2);
		x += dir;
	}
	return (0);
}

int				draw_vert(t_point v1, t_point v2, t_mlx_img mlx_img)
{
	float		x;
	float		y;
	int			dir;

	x = v1.calc.x;
	y = v1.calc.y;
	dir = -1;
	if (y < v2.calc.y)
		dir = 1;
	while ((int)y != (int)v2.calc.y)
	{
		add_pixel(mlx_img, x, y, (v1.colour + v2.colour) / 2);
		y += dir;
	}
	return (0);
}

int				draw_formula(t_point v1, t_point v2, t_mlx_img mlx_img)
{
	float		m;
	float		c;
	float		x;
	float		y;
	int			xdif;
	int			ydif;

	m = (v2.calc.y - v1.calc.y) / (v2.calc.x - v1.calc.x);
	c = v1.calc.y - (v1.calc.x * m);
	x = v1.calc.x;
	y = m * x + c;
	xdif = -1;
	if ((v2.calc.x - v1.calc.x) > 0)
		xdif = 1;
	ydif = -1;
	if ((v2.calc.y - v1.calc.y) > 0)
		ydif = 1;
	while ((int)x != (int)v2.calc.x && (int)y != (int)v2.calc.y)
	{
		add_pixel(mlx_img, x, y, (v1.colour + v2.colour) / 2);
		if (m > 1)
		{
			y += ydif;
			x = (y - c) / m;
		}
		else
		{
			x += xdif;
			y = m * x + c;
		}
	}
	return (0);
}

void			draw_grid(t_mlx_obj *o)
{
	int			i;
	int			j;
	t_mlx_img	mlx_img;
	void		*mlx_img_p;

	i = 0;
	j = 0;
	mlx_img_p = mlx_new_image(o->mlx_ptr, o->width, o->height);
	mlx_img.line = mlx_get_data_addr(mlx_img_p, &(mlx_img.bpp),
					&(mlx_img.size_l), &(mlx_img.endian));
	while (o->grid[i] != NULL)
	{
		j = 0;
		while (o->grid[i][j].og.null == 0)
		{
			o->grid[i][j].calc = apply_mat(o->grid[i][j].og, o->m);
			o->grid[i][j].calc.x += 800;
			o->grid[i][j].calc.y += 450;
			draw_point(o, i, j, mlx_img);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(o->mlx_ptr, o->mlx_win, mlx_img_p, 0, 0);
	mlx_destroy_image(o->mlx_ptr, mlx_img_p);
}
