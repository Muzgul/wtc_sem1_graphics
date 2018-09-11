/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 07:51:50 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/21 07:51:52 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_cam	rotate_cam(t_cam c, float angle)
{
	t_mat2	m;

	m = mat2_rotate(angle);
	c.dir = mat2_apply(c.dir, m);
	c.plane = mat2_apply(c.plane, m);
	return (c);
}

int		check_pos(t_hold *h, float posx, float posy)
{
	int ret;

	ret = 0;
	if ((int)posx >= 0 && (int)posx < h->g.w)
		ret += 1;
	if ((int)posy >= 0 && (int)posy < h->g.h)
		ret += 2;
	if (ret == 3 && h->g.grid[(int)posy][(int)posx] <= 0)
		return (0);
	return (-1);
}

t_cam	move_cam(t_hold *hold, float dist)
{
	float	posx;
	float	posy;
	int		res;

	posx = hold->c.dir.x * dist + hold->c.pos.x;
	posy = hold->c.dir.y * dist + hold->c.pos.y;
	res = check_pos(hold, posx, posy);
	if (res == 0)
	{
		hold->c.pos.x = posx;
		hold->c.pos.y = posy;
	}
	return (hold->c);
}
