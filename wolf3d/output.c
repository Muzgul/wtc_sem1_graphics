/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:57:46 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/15 15:57:47 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_strarr(char **strarr)
{
	int i;

	i = 0;
	while (strarr[i] != NULL)
	{
		ft_putendl(strarr[i]);
		i++;
	}
}

void	print_grid(t_grid g)
{
	int i;
	int j;

	i = 0;
	while (i < g.h)
	{
		j = 0;
		while (j < g.w)
		{
			ft_putnbr(g.grid[i][j]);
			ft_putchar('|');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_cam(t_cam c)
{
	ft_putstr("*** cam x10 ***\n");
	ft_putstr("-pos: x (");
	ft_putnbr(c.pos.x * 10);
	ft_putstr(") y(");
	ft_putnbr(c.pos.y * 10);
	ft_putstr(")\n");
	ft_putstr("-dir: x (");
	ft_putnbr(c.dir.x * 10);
	ft_putstr(") y(");
	ft_putnbr(c.dir.y * 10);
	ft_putstr(")\n");
	ft_putstr("-plane: x (");
	ft_putnbr(c.plane.x * 10);
	ft_putstr(") y(");
	ft_putnbr(c.plane.y * 10);
	ft_putstr(")\n");
	ft_putendl("\n***************");
}

void	print_err(char *str)
{
	ft_putstr("ERROR: ");
	ft_putendl(str);
	ft_putendl("[ EXIT ]");
	exit(0);
}
