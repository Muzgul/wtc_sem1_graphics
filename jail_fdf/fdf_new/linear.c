/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 11:42:00 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 11:42:02 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    shift_y(ft_vector **grid, float diff)
{
    int     i;
    int     j;

    i = 0;
    while (grid[i] != NULL)
    {
        j = 0;
        while (grid[i][j].null == 0)
        {
            grid[i][j].y += diff;
            j++;
        }
        i++;
    }
}

void    shift_z(ft_vector **grid, float diff)
{
    int     i;
    int     j;

    i = 0;
    while (grid[i] != NULL)
    {
        j = 0;
        while (grid[i][j].null == 0)
        {
            grid[i][j].z += diff;
            j++;
        }
        i++;
    }
}

void    shift_x(ft_vector **grid, float diff)
{
    int     i;
    int     j;

    i = 0;
    while (grid[i] != NULL)
    {
        j = 0;
        while (grid[i][j].null == 0)
        {
            grid[i][j].x += diff;
            j++;
        }
        i++;
    }
}