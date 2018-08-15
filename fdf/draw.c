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

float			t_abs(float n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int				draw_line(t_point v1, t_point v2, t_mlx_img mlx_img)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;

	dx = v2.calc.x - v1.calc.x;
	dy = v2.calc.y - v1.calc.y;
	step = t_abs(dy);
	if (t_abs(dx) >= t_abs(dy))
		step = t_abs(dx);
	dx /= step;
	dy /= step;
	x = v1.calc.x;
	y = v1.calc.y;
	while ((int)step > 0)
	{
		add_pixel(mlx_img, x, y, v1.colour);
		x += dx;
		y += dy;
		step--;
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
