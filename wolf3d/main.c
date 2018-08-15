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
	int fd;
	char **strarr;

	strarr = NULL;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		strarr = read_to_array(fd);
		print_strarr(strarr);
	}
	return (0);
}
