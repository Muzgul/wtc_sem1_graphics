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

int			draw_horiz(ft_vector v1, ft_vector v2, void *mlx_ptr, void *mlx_win)
{
	ft_putstr("draw_horiz ");
	ft_putnbr(v1.x);
	ft_putstr("->");
	ft_putnbr(v2.x);
	float	x;
	float	y;
	int		dir;

	x = v1.x;
	y = v1.y;
	dir = -1;
	if (x < v2.x)
		dir = 1;
	while ((int)x != (int)v2.x)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, x, y, v1.c);
		x += dir;
	}
	ft_putendl(" ...finished");
	return (0);
}

int			draw_vert(ft_vector v1, ft_vector v2, void *mlx_ptr, void *mlx_win)
{
	ft_putstr("draw_vert ");
	ft_putnbr(v1.y);
	ft_putstr("->");
	ft_putnbr(v2.y);
	float	x;
	float	y;
	int		dir;

	x = v1.x;
	y = v1.y;
	dir = -1;
	if (y < v2.y)
		dir = 1;
	while ((int)y != (int)v2.y)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, x, y, v1.c);
		y += dir;
	}
	ft_putendl(" ...finished");
	return (0);
}

int			draw_line(ft_vector v1, ft_vector v2, void *mlx_ptr, void *mlx_win)
{
	float	m;
	float	c;
	float	x;
	float	y;
	int		xdif;
	int		ydif;

	if (v1.x == v2.x)
		return (draw_vert(v1, v2, mlx_ptr, mlx_win));
	if (v1.y == v2.y)
		return (draw_horiz(v1, v2, mlx_ptr, mlx_win));
	m = (v2.y - v1.y)/(v2.x - v1.x);
	c = v1.y - (v1.x * m);
	x = v1.x;
	y = m * x + c;
	xdif = -1;
	if ((v2.x - v1.x) > 0)
		xdif = 1;
	ydif = -1;
	if ((v2.y - v1.y) > 0)
		ydif = 1;
	while ((int)x != (int)v2.x && (int)y != (int)v2.y)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, x, y, v1.c);
		if (m > 1)
		{
			y += ydif;
			x = (y - c)/m;
		}
		else
		{
			x += xdif;
			y = m * x + c;
		}
	}
	printf("y=%fx + %f\n", m, c);	
	return (0);
}

void		draw_vector(ft_vector v, void *mlx_ptr, void *mlx_win)
{
	mlx_pixel_put(mlx_ptr, mlx_win, v.x, v.y, v.c);
}
