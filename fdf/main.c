/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:00:31 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/04 13:00:32 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	char		**strarr;
	int			fd;
	t_mlx_obj	*mlx_obj;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			strarr = read_to_array(fd);
			if (strarr == NULL)
				return (0);
			mlx_obj = get_mlx_obj(strarr, 1600, 900, 90);
			free_strarr(strarr);
			mlx_key_hook(mlx_obj->mlx_win, key_hook, mlx_obj);
			draw_grid(mlx_obj);
			mlx_loop(mlx_obj->mlx_ptr);
		}
	}
	return (0);
}
