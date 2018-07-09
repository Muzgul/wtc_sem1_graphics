/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:09:45 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 13:09:46 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    apply_transform(ft_vector **grid, ft_vector (*f)(ft_vector, float), float value)
{
    int i;
    int j;

    i = 0;
    while (grid[i] != NULL)
    {
        j = 0;
        while (grid[i][j].null == 0)
        {
            grid[i][j] = (*f)(grid[i][j], value);
            j++;
        }
        i++;
    }
}
