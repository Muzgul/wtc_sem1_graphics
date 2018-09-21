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

int		main(int ac, char **av)
{
	int			fd;
	t_holder	stuff;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 1)
			return (0);
		stuff = setup(fd);
		trace(stuff);
		mlx_loop(stuff.mlx_ptr);
		free_list(&stuff.head);
	}
	return (0);
}
