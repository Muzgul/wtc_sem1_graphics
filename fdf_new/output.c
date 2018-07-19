/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:12:37 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 11:12:38 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_grid(char **grid)
{
	int i;

	i = 0;
	while (grid[i] != NULL)
	{
		ft_putendl(grid[i]);
		i++;
	}
}

void		print_vector(ft_vector v)
{
	ft_putstr(" V[ ");
	if (v.null == 0)
	{
		ft_putnbr(v.x);
		ft_putstr(" , ");
		ft_putnbr(v.y);
		ft_putstr(" , ");
		ft_putnbr(v.z);
		ft_putstr(" , ");
		ft_putnbr(v.w);
	}
	else
		ft_putstr("(null)");
	ft_putstr(" ] ");
}

void		print_vgrid(ft_vector **grid)
{
	int			i;
	int			j;
	ft_vector	v;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		ft_putendl("{");
		while ((v = grid[i][j]).null == 0)
		{
			print_vector(v);
			j++;
		}
		ft_putendl("\n}");
		i++;
	}
}
