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

int		main(int argc, char **argv)
{
	int		fd;
	char	**strarr;
	t_hold	*hold;

	if (argc > 1)
	{
		if ((fd = open(argv[1], O_RDONLY)) > 0)
		{
			strarr = read_to_array(fd);
			hold = (t_hold *)malloc(sizeof(t_hold));
			hold->g = init_grid(strarr);
			hold->c = init_cam(hold->g);
			hold->o = init_mlx(900, 1600);
			init_hook(hold);
			search_and_draw(hold->g, hold->c, hold->o);
			mlx_loop(hold->o.mlx_ptr);
			free_grid(hold->g);
			free(hold);
		}
		else
			ft_putstr("ERROR: Invalid input file!\n[ EXIT ]\n");
	}
	else
		ft_putstr("ERROR: Invalid number of arguments!\n[ EXIT ]\n");
	return (0);
}
