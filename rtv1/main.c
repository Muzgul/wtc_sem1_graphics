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
		// t_vector ray2;
		// t_object *node;
		// t_object *node2;
		// double temp = 0;
		// double res2 = 0;
		double res;
		t_object light;
		light.origin = vect_get(2, 5, -10);

		i = 0;
		while (i < m.h)
		{
			j = 0;
			while (j < m.w)
			{

				/*
					NOTES ON HOW TO FIX DIS SHIT

					ISSUE ON THE LIGHT NOT WORKING
					NEED TO THINK ABOUT IF THE LIGHT RAY IS HITTING A DIFFERENT SIDE OF THE SHAPE AND WHAT THAT MEANS TO THE DISTANCE
					THINK ABOUT IT (THE GREEN SHIT)
						
				*/
				ray = vect_norm(cam_ray(j, i, m, c));

				// *** new code ***
				double colour;
				double brightness;
				res = shortest_dist(head, c.pos, ray, &colour);
				if (res > 0)
				{
					brightness = light_intensity(head, light, vect_mult(ray, res - 0.001));
					if (brightness >= 0)
						mlx_pixel_put(mlx_ptr, mlx_win, j, i, adjust_colour(colour, brightness, 10));
					if (brightness == -1)
						mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255 * 256);
					if (brightness == -2)
						mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255 * 65536);
					// if (brightness != 1)
					// 	printf("bright: %f\n", brightness);
					// if (brightness > 0)
					// {
					// 	if (brightness > 1.001)
					// 		mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255 * 256);
					// 	else
					// 		mlx_pixel_put(mlx_ptr, mlx_win, j, i, adjust_colour(colour, brightness));
					// }
				}

				// node = head;
				// while (node != NULL)
				// {
				// 	if ((res = test_object(node, c.pos, ray)) > 0)
				// 	{
				// 		printf("Res: %f\n", res);
				// 		// mlx_pixel_put(mlx_ptr, mlx_win, j, i, node->colour);
				// 		node2 = head;
				// 		ray2 = vect_mult(ray, res - 1);
				// 		while (node2 != NULL)
				// 		{
				// 			res2 = test_object(node2, ray2, vect_norm(vect_sub(light.origin, ray2)));
				// 			if (fabs(res2) < 1)
				// 				mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255 * 256);
				// 			if (res2 > 0 && node2 != node)
				// 			{
				// 				mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255);
				// 				temp = 1;
				// 				break;
				// 				res2 = 0;
				// 			}
				// 			printf("Res2: %f\n", res);
				// 			if (res2 > 0)
				// 			{
				// 				temp = 1;
				// 				mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255);
				// 			}
				// 			// if (res2 < 0)
				// 			// 	mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255 * 256);
				// 			// if (res2 == 0)
				// 			// 	mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255 * 65536);
				// 			node2 = node2->next;
				// 		}
				// 		if (temp == 0)
				// 			mlx_pixel_put(mlx_ptr, mlx_win, j, i, node->colour);
				// 		// if (temp == -1)
				// 		// 	mlx_pixel_put(mlx_ptr, mlx_win, j, i, 255 * 256);
				// 	}
				// 	node = node->next;
				// }
				j++;
			}
			i++;
		}

		mlx_loop(mlx_ptr);
		free_list(&head);
	}
	return (0);
}
