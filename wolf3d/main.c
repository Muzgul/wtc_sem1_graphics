/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:57:40 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/15 15:57:42 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

float	search_to(t_grid g, t_vector f, t_vector t)
{
	int mapx;
	int mapy;
	float sdistx;
	float sdisty;
	float ddistx;
	float ddisty;
	float stepx;
	float stepy;

	mapx = (int)f.x;
	mapy = (int)f.y;
	ddistx = fabsf(1 / t.x);
	ddisty = fabsf(1 / t.y);
	if (t.x < 0)
	{
		stepx = -1;
		sdistx = (f.x - mapx) * ddistx;
	}
	else
	{
		stepx = 1;
		sdistx = (f.x + (float)1 - mapx) * ddistx;
	}
	if (t.y < 0)
	{
		stepy = -1;
		sdisty = (f.y - mapy) * ddisty;
	}
	else
	{
		stepy = 1;
		sdisty = (f.y + (float)1 - mapy) * ddisty;
	}

	int hit;
	int side;
	hit = 0;
	float perpWallDist;
	perpWallDist = 0;
	while (hit == 0)
	{
		if (sdistx < sdisty)
		{
			sdistx += ddistx;
			mapx += stepx;
			side = 0;
		}
		else
		{
			sdisty += ddisty;
			mapy += stepy;
			side = 1;
		}
		if (mapx < g.w && mapy < g.h && mapx >= 0 && mapy >= 0)
		{
			printf("\t\t Before grid[%i][%i]\n", mapy, mapx);
			if (g.grid[mapy][mapx] > 0)
			{
				hit = 1;
				if (side == 0) 
					perpWallDist = (mapx - f.x + (1 - stepx) / 2) / t.x;
      			else
				  	perpWallDist = (mapx - f.x + (1 - stepx) / 2) / t.x;
				//printf("hit with dist: %f", perpWallDist);
			
			}
		}
		else
		{
			printf("mapx(%i), mapy(%i)\n", mapx, mapy);
			ft_putendl("Ran out");
			return (0);
		}
	}
	return (perpWallDist);
}

void		add_pixel(t_mlx_img mlx_img, int x, int y, int color)
{
	int		pos;

	pos = y * mlx_img.size_l;
	pos += x * (mlx_img.bpp / 8);
	if (pos > 1600 * mlx_img.size_l)
		ft_putstr("TOO MANY THINGS!!!");
	else
		printf("\tbytes: %i vs %i\n", pos, 1600 * mlx_img.size_l);
	mlx_img.img[pos] = ((color / 1000000) % 1000) - 128;
	mlx_img.img[pos + 1] = ((color / 1000) % 1000) - 128;
	mlx_img.img[pos + 2] = color % 1000;
	mlx_img.img[pos + 3] = 1;
}

void	draw_col(t_mlx_obj o, int col, float dist)
{
	int		height;
	int		to_skip;
	int		i;

	// if ((int)dist > 0)
	height = o.height / dist;
	to_skip = (o.height - height) / 2;
	i = to_skip;
	printf("\tat (%i, %i) with height %i / %f = %i and offset(%i)\n", col, i, o.height, dist, height, to_skip);
	while (i < o.height && i < (to_skip + height))
	{
		printf("\t\t\tx: %i, y: %i\t", col, i);
		add_pixel(o.mlx_img, col, i, 10840509);
		i++;
	}
	ft_putchar('\n');
}

void	search_and_draw(t_grid g, t_cam c, t_mlx_obj o)
{
	t_vector	v;
	float		step;
	int			i;
	float		dir_dist;
	float		angle;
	float		dist;

	o.mlx_img.mlx_img = mlx_new_image(o.mlx_ptr, o.width, o.height);
	o.mlx_img.img = mlx_get_data_addr(o.mlx_img.mlx_img, &o.mlx_img.bpp, &o.mlx_img.size_l, &o.mlx_img.e);
	step = c.plane / (o.width / 2);
	dir_dist = vect_dist(c.pos, vect_add(c.pos, c.dir));
	i = 0;
	while (i < o.width)
	{
		angle = atan((c.plane - (step * i)) / dir_dist);
		if (angle < 0)
			angle = (360 * (M_PI * 180)) + angle;
		v = vect_rotate(c.dir, angle);
		dist = search_to(g, c.pos, v);
		if ((int)dist != 0 && (int)dist > 0)
			draw_col(o, i, dist);
		i++;
	}
	mlx_clear_window(o.mlx_ptr, o.mlx_win);
	mlx_put_image_to_window(o.mlx_ptr, o.mlx_win, o.mlx_img.mlx_img, 0, 0);
	mlx_destroy_image(o.mlx_ptr, o.mlx_img.mlx_img);
}

int key_hook(int keycode, t_hold *hold)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		hold->c = rotate_cam(hold->c, -5 * (M_PI / 180));
		search_and_draw(hold->g, hold->c, hold->o);
	}
	if (keycode == 124)
	{
		hold->c = rotate_cam(hold->c, 5 * (M_PI / 180));
		search_and_draw(hold->g, hold->c, hold->o);
	}
	if (keycode == 126)
	{
		hold->c.pos.x += 0.1;
		search_and_draw(hold->g, hold->c, hold->o);
	}
	if (keycode == 125)
	{
		hold->c.pos.x -= 0.1;
		search_and_draw(hold->g, hold->c, hold->o);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	char **strarr;
	t_grid g;
	t_mlx_obj mlx_obj;
	t_cam c;
	t_hold *hold;

	strarr = NULL;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		strarr = read_to_array(fd);
		g = init_grid(strarr);
		print_grid(g);
		c = init_cam(g, 90 * (M_PI / 180));
		print_cam(c);
		
		mlx_obj = init_mlx(900, 1600);
		search_and_draw(g, c, mlx_obj);
		hold = (t_hold *)malloc(sizeof(t_hold));
		hold->c = c;
		hold->g = g;
		hold->o = mlx_obj;
		mlx_key_hook(mlx_obj.mlx_win, key_hook, hold);
		mlx_loop(mlx_obj.mlx_ptr);
		free_grid(g);
	}
	return (0);
}
