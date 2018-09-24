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

	stuff.head = read_file(fd, &stuff.light, &stuff.c);
	if (stuff.head == NULL)
		input_error(&stuff.head, NULL, "Error on input!");
	stuff.m.h = 900;
	stuff.m.w = 900;
	stuff.mlx_ptr = mlx_init();
	stuff.mlx_win = mlx_new_window(stuff.mlx_ptr, stuff.m.w, stuff.m.h, "RTV1");
	mlx_key_hook(stuff.mlx_win, key_hook, NULL);
	stuff.c.fov = angl(90);
	return (stuff);
}

int			key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}
