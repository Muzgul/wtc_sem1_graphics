/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 12:21:38 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/24 12:21:39 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	close_hook(int keycode, t_hold *hold)
{
	(void)keycode;
	(void)hold;
	sleep(30);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_hold *hold)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		hold->c = rotate_cam(hold->c, 5 * (M_PI / 180));
		search_and_draw(hold->g, hold->c, hold->o);
	}
	if (keycode == 124)
	{
		hold->c = rotate_cam(hold->c, -5 * (M_PI / 180));
		search_and_draw(hold->g, hold->c, hold->o);
	}
	if (keycode == 126)
	{
		hold->c = move_cam(hold, 0.2);
		search_and_draw(hold->g, hold->c, hold->o);
	}
	if (keycode == 125)
	{
		hold->c = move_cam(hold, -0.2);
		search_and_draw(hold->g, hold->c, hold->o);
	}
	return (0);
}
