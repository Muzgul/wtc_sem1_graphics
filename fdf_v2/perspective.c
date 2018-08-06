/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:31:15 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/04 14:31:16 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ft_mat4     perspective_mat(float near, float far, float fov)
{
    ft_mat4     new;

    new = get_mat4();
    new.a[0] = 1/tan((fov/2) * (M_PI / 180)); //1/((aspect) * tan(fov));
	new.b[1] = 1/tan((fov/2) * (M_PI / 180)); //1/tan(fov);
	new.c[2] = (far / (far - near)) * -1;//(near + far)/(near - far);
	new.c[3] = ((far * near) / (far - near)) * -1;//(2 * near * far)/(near - far);
	new.d[2] = -1;
    return (new);
}
