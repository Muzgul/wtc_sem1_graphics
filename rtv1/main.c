/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 14:49:56 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/31 14:49:57 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

int		key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	int fd;
	t_object *head;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 1)
			return (0);
		head = read_objects(fd);
		if (head == NULL)
			exit (0);
		print_list(head);

		t_m_img m;
		m.h = 900;
		m.w = 900;


		void *mlx_ptr = mlx_init();
		void *mlx_win = mlx_new_window(mlx_ptr, m.w, m.h, "stuff");
		mlx_key_hook(mlx_win, key_hook, NULL);

		t_cam c;
		c.pos = vect_get(0, 0, 0);
		c.dir = vect_get(0, 0, -1);
		c.fov = angl(90);

		int i;
		int j;
		t_vector ray;
		t_object *node;
		double res;

		i = 0;
		while (i < m.h)
		{
			j = 0;
			while (j < m.w)
			{
				ray = cam_ray(j, i, m, c);
				ray = vect_norm(ray);
				node = head;
				while (node != NULL)
				{
					if ((res = test_object(node, c.pos, ray)) > 0)
					{
						// if (res == 1)
							mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255255255);
						if (res == 2)
							mlx_pixel_put(mlx_ptr, mlx_win, j, i, 254245254);
						// printf("Dist: %f\n", vect_get_dist(vect_mult(ray, res), ray));
					}
					node = node->next;
				}
				j++;
			}
			i++;
		}

		mlx_loop(mlx_ptr);
		free_list(&head);
	}
	return (0);
}
