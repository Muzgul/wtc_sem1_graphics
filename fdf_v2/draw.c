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
	// if (z_value < 0)
	// 	z_value *= -1;
	// if (z_value % 13 == 0)
	// 	return (16101441);
	// if (z_value % 11 == 0)
	// 	return (4567965);
	// if (z_value % 7 == 0)
	// 	return (6139362);
	if (z_value % 5 == 0)
		return (255000000);
	if (z_value % 3 == 0)
		return (255000);
	if (z_value % 2 == 0)
		return (255);
	return (255255255);
}

int			draw_horiz(ft_point v1, ft_point v2, void *mlx_ptr, void *mlx_win)
{
	// ft_putstr("draw_horiz ");
	// ft_putnbr(v1.calc.x);
	// ft_putstr("->");
	// ft_putnbr(v2.calc.x);
	float	x;
	float	y;
	int		dir;

	x = v1.calc.x;
	y = v1.calc.y;
	dir = -1;
	if (x < v2.calc.x)
		dir = 1;
	while ((int)x != (int)v2.calc.x)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, x, y, v1.colour);
		x += dir;
	}
	// ft_putendl(" ...finished");
	return (0);
}

int			draw_vert(ft_point v1, ft_point v2, void *mlx_ptr, void *mlx_win)
{
	// ft_putstr("draw_vert ");
	// ft_putnbr(v1.calc.y);
	// ft_putstr("->");
	// ft_putnbr(v2.calc.y);
	float	x;
	float	y;
	int		dir;

	x = v1.calc.x;
	y = v1.calc.y;
	dir = -1;
	if (y < v2.calc.y)
		dir = 1;
	while ((int)y != (int)v2.calc.y)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, x, y, v1.colour);
		y += dir;
	}
	// ft_putendl(" ...finished");
	return (0);
}

int			draw_line(ft_point v1, ft_point v2, void *mlx_ptr, void *mlx_win)
{
	float	m;
	float	c;
	float	x;
	float	y;
	int		xdif;
	int		ydif;

	if (v1.calc.x == v2.calc.x)
		return (draw_vert(v1, v2, mlx_ptr, mlx_win));
	if (v1.calc.y == v2.calc.y)
		return (draw_horiz(v1, v2, mlx_ptr, mlx_win));
	m = (v2.calc.y - v1.calc.y)/(v2.calc.x - v1.calc.x);
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
		mlx_pixel_put(mlx_ptr, mlx_win, x, y, v1.colour);
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
	return (0);
}

void	temp_add_pixel(char *line, int bpp, int size_l, int x, int y, int color)
{
	int		pos;

	pos = y * size_l;
	pos += x * (bpp/8);
	line[pos] = ((color/1000000) % 1000) - 128;
	line[pos + 1] = ((color/1000) % 1000) - 128;
	line[pos + 2] = color % 1000;
	line[pos + 3] = 1;
}

void	temp_draw_line(ft_point p1, ft_point p2, char *line, int bpp, int size_l)
{
	ft_putendl("in draw");
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		steps;
	int		i;

	dx = p1.calc.x - p2.calc.x;
	dy = p1.calc.y - p2.calc.y;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	dx = dx /(float) steps;
	dy = dy /(float) steps;
	i = 0;
	x = p1.calc.x;
	y = p1.calc.y;
	while (i < steps)
	{
		x += dx;
		y += dy;
		if (x > 0 && x < 1600 && y > 0 && y < 900)
			temp_add_pixel(line, bpp, size_l, x, y, p1.colour);
		i++;
	}
}

int		in_bounds(ft_vector v, int width, int height)
{
	if (v.x > 0 && v.x < width && v.y > 0 && v.y < height)
		return (1);
	return (0);
}

void	draw_grid(ft_mlx_obj *o)
{
	int i;
	int j;

	i = 0;
	j = 0;
	//mlx_clear_window(o->mlx_ptr, o->mlx_win);
	void *mlx_img;

	mlx_img = mlx_new_image(o->mlx_ptr, 1600, 900);
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	char *res;
	res = mlx_get_data_addr(mlx_img, &bits_per_pixel, &size_line, &endian);
	ft_putnbr( bits_per_pixel );
	ft_putstr( "(bpp), ");
	ft_putnbr( size_line );
	ft_putstr(" (sl), ");
	ft_putnbr(endian);
	ft_putstr(" (e) -> ");
	ft_putendl(res);
	
	
	
	while (o->grid[i] != NULL)
	{
		j = 0;
		while (o->grid[i][j].calc.null == 0)
		{
			// o->grid[i][j].calc.z *= -1;
			// o->grid[i][j].calc.z -= 5;
            o->grid[i][j].calc = apply_mat(o->grid[i][j].og, o->m);
            o->grid[i][j].calc.x += 800;
            o->grid[i][j].calc.y += 450;
			
			if (o->grid[i][j].calc.x > 0 && o->grid[i][j].calc.x < 1600 && o->grid[i][j].calc.y > 0 && o->grid[i][j].calc.y < 900)
			{
				temp_add_pixel(res, bits_per_pixel, size_line, o->grid[i][j].calc.x, o->grid[i][j].calc.y, o->grid[i][j].colour);
				// draw_vector(o->grid[i][j], o->mlx_ptr, o->mlx_win);
				if (i > 0 && in_bounds(o->grid[i][j].calc, 1600, 900) > 0 && in_bounds(o->grid[i - 1][j].calc, 1600, 900) > 0)
					temp_draw_line(o->grid[i][j], o->grid[i - 1][j], res, bits_per_pixel, size_line);
				if (j > 0 && in_bounds(o->grid[i][j].calc, 1600, 900) > 0 && in_bounds(o->grid[i][j - 1].calc, 1600, 900) > 0)
					temp_draw_line(o->grid[i][j], o->grid[i][j - 1], res, bits_per_pixel, size_line);
				// if (i > 0 && o->grid[i][j].colour == o->grid[i - 1][j].colour)
				// 	draw_line(o->grid[i][j], o->grid[i - 1][j], o->mlx_ptr, o->mlx_win);
				// if (j > 0 && o->grid[i][j].colour == o->grid[i][j - 1].colour)
				// 	draw_line(o->grid[i][j], o->grid[i][j - 1], o->mlx_ptr, o->mlx_win);
				// if (i > 0 && j > 0 && o->grid[i][j].colour == o->grid[i - 1][j - 1].colour)
				// 	draw_line(o->grid[i][j], o->grid[i - 1][j - 1], o->mlx_ptr, o->mlx_win);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(o->mlx_ptr, o->mlx_win, mlx_img, 0, 0);
}

