/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 12:24:11 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/24 12:24:12 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_ray_delta(t_cam c, t_vector *ray, t_vector *delta, float camx)
{
	ray->x = c.dir.x + (c.plane.x * camx);
	ray->y = c.dir.y + (c.plane.y * camx);
	delta->x = fabsf(1 / ray->x);
	delta->y = fabsf(1 / ray->y);
}

t_vector	set_side_step(t_cam c, t_vector *s, t_vector *d, t_vector *r)
{
	t_vector step;

	if (r->x < 0)
	{
		step.x = -1;
		s->x = (c.pos.x - (int)c.pos.x) * d->x;
	}
	else
	{
		step.x = 1;
		s->x = ((int)c.pos.x + (float)1 - c.pos.x) * d->x;
	}
	if (r->y < 0)
	{
		step.y = -1;
		s->y = (c.pos.y - (int)c.pos.y) * d->y;
	}
	else
	{
		step.y = 1;
		s->y = ((int)c.pos.y + (float)1 - c.pos.y) * d->y;
	}
	return (step);
}

int			calc_wall(t_vector *s, t_vector *d, t_vector *step, t_vector *m)
{
	if (s->x < s->y)
	{
		s->x += d->x;
		m->x += (int)step->x;
		return (0);
	}
	else
	{
		s->y += d->y;
		m->y += (int)step->y;
		return (1);
	}
}

float		for_hit(t_calc *b, t_grid g, t_cam c, int *wall)
{
	int		hit;
	float	wall_dist;

	hit = 0;
	while (hit == 0)
	{
		*wall = calc_wall(&b->side, &b->delta, &b->step, &b->map);
		if (b->map.x >= 0 && b->map.x < g.w && b->map.y >= 0 && b->map.y < g.h)
		{
			if (abs(g.grid[(int)b->map.y][(int)b->map.x]) > 0)
				hit = 1;
		}
		else
			hit = -1;
	}
	if (hit == -1)
		return (0);
	if (*wall == 0)
		wall_dist = (b->map.x - c.pos.x + (1 - (int)b->step.x) / 2) / b->ray.x;
	else
		wall_dist = (b->map.y - c.pos.y + (1 - (int)b->step.y) / 2) / b->ray.y;
	return (wall_dist);
}

float		search_to(t_mlx_obj o, t_cam c, t_grid g, int col)
{
	float	slice;
	float	wall_dist;
	t_calc	b;
	int		wall;

	slice = 2 * col / (float)o.width - 1;
	set_ray_delta(c, &b.ray, &b.delta, slice);
	b.step = set_side_step(c, &b.side, &b.delta, &b.ray);
	b.map.x = (int)c.pos.x;
	b.map.y = (int)c.pos.y;
	wall_dist = for_hit(&b, g, c, &wall);
	draw_col(o, col, wall_dist, wall);
	return (0);
}
