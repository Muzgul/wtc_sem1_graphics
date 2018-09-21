/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:39:53 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/21 11:39:56 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_holder	setup(int fd)
{
	t_holder stuff;

	stuff.head = read_objects(fd);
	if (stuff.head == NULL)
		exit(0);
	stuff.m.h = 900;
	stuff.m.w = 900;
	stuff.mlx_ptr = mlx_init();
	stuff.mlx_win = mlx_new_window(stuff.mlx_ptr, stuff.m.w, stuff.m.h, "RTV1");
	mlx_key_hook(stuff.mlx_win, key_hook, NULL);
	stuff.c.pos = vect_get(0, 0, 0);
	stuff.c.dir = vect_get(0, 0, -1);
	stuff.c.fov = angl(90);
	stuff.light = vect_get(0, 0, 0);
	return (stuff);
}

int			key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}
