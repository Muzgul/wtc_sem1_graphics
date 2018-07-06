/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:13:48 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/06 12:13:49 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		draw_horiz(mlx_ctrl *my_mlx, int *p1, int *p2)
{
	ft_putstr("draw_horiz: ");
	ft_putnbr(p1[0]);
	ft_putstr("(x) -> ");
	ft_putnbr(p2[0]);
	ft_putendl("(x)");
	int x;
	int y;
	int diff;
	int *p;

	if (p1 == NULL || p2 == NULL)
		return (-1);
	y = p1[1];
	if (p1[0] < p2[0])
	{
		x = p1[0];
		diff = p2[0] - p1[0];
	}
	else
	{
		x = p2[0];
		diff = p1[0] - p2[0];
	}
	p = make_point(x, y, p1[2]);
	while (p[0] < (x + diff))
	{
		temp_draw_point(my_mlx, p);
		p[0] += 1;
	}
	return (1);
}

int		draw_vert(mlx_ctrl *my_mlx, int *p1, int *p2)
{
	ft_putstr("draw_vert: ");
	ft_putnbr(p1[1]);
	ft_putstr("(y) -> ");
	ft_putnbr(p2[1]);
	ft_putendl("(y)");
	int x;
	int y;
	int diff;
	int *p;

	if (p1 == NULL || p2 == NULL)
		return (-1);
	x = p1[0];
	if (p1[1] < p2[1])
	{
		y = p1[1];
		diff = p2[1] - p1[1];
	}
	else
	{
		y = p2[1];
		diff = p1[1] - p2[1];
	}
	p = make_point(x, y, p1[2]);
	while (p[1] < (y + diff))
	{
		temp_draw_point(my_mlx, p);
		p[1] += 1;
	}
	if (p)
		free(p);
	return (1);
}

int		draw_angle(mlx_ctrl *my_mlx, int *p1, int *p2, float m, float c)
{
	int x;
	int y;
	int coef;
	int *p;

	coef = -1;
	if (p1[0] < p2[0])
		coef = 1;
	x = p1[0] + coef;
	y = (m * x) + c;
	p = make_point(x, y, p1[2]);
	if (p == NULL)
	{
		ft_putendl("p is (null)");
		return (-1);
	}
	while (p[0] != p2[0])
	{
		temp_draw_point(my_mlx, p);
		p[0] += coef;
		p[1] = (float)(m * (float)p[0]) + c;
	}
	free(p);
	return (1);
}

int     temp_draw_line(mlx_ctrl *my_mlx, int *p1, int *p2)
{
    float   m;
    float   c;

    if (p1 == NULL || p2 == NULL)
        return (-1);
	if (p1[0] == p2[0])
		return (draw_vert(my_mlx, p1, p2));
	if (p1[1] == p2[1])
		return (draw_horiz(my_mlx, p1, p2));
	m = (p1[1] - p2[1])/(p1[0] - p2[0]);
    c = p1[1] - (p1[0] * m);
    ft_putstr("y= ( ");
    ft_putnbr(p1[1] - p2[1]);
	ft_putchar('/');
	ft_putnbr(p1[0] - p2[0]);
    ft_putstr(" )x + ");
    ft_putnbr(c);
    ft_putendl(";");
	return (draw_angle(my_mlx, p1, p2, m, c));
}
