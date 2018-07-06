/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:13:43 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/06 12:13:44 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int     *make_point(int x, int y, int z)
{
    int *arr;

    if (x < 0 || y < 0)
        return (NULL);
    arr = (int *)malloc(sizeof(int) * 3);
    if (arr == NULL)
        return (NULL);
    arr[0] = x;
    arr[1] = y;
    arr[2] = z;
    return (arr);
}

int     get_color(int z_value)
{
    if (z_value % 13 == 0)
        return (16101441);
    if (z_value % 11 == 0)
        return (4567965);
    if (z_value % 7 == 0)
        return (6139362);
    if (z_value % 5 == 0)
        return (10840509);
    if (z_value % 3 == 0)
        return (15495267);
    if (z_value % 2 == 0)
        return (9935514);
    return (16777215);
}

int     temp_draw_point(mlx_ctrl *my_mlx, int *point)
{
    int color;
    int res;

    color = get_color(point[2]);
    res = mlx_pixel_put(my_mlx->mlx_ptr, my_mlx->mlx_win, point[0] + 250, point[1] + 250, color);
    return (res);
}
