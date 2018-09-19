/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 09:53:54 by mmacdona          #+#    #+#             */
/*   Updated: 2018/09/19 09:53:55 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int     add_shade(t_vector colour, double brightness, int strength)
{
    double  factor;

    factor = (double)strength / brightness;
    if (factor >= 1)
        printf("factor: %f\n", factor);
    colour.x *= factor;
    colour.y *= factor;
    colour.z *= factor;
    return (colour.x * 65536 + colour.y * 256 + colour.z);
}

int     add_tint(t_vector colour, double brightness, int strength)
{
    colour.x += (255 - colour.x) * (brightness / strength);
    colour.y += (255 - colour.y) * (brightness / strength);
    colour.z += (255 - colour.z) * (brightness / strength);
    return (colour.x * 65536 + colour.y * 256 + colour.z);
}

int     adjust_colour(int colour, double brightness, int strength)
{
    t_vector    rgb;
    long        rgb_c;

    rgb_c = colour;
    rgb.x = (int)(rgb_c % 0x1000000 / 0x10000);
    rgb.y = (int)(rgb_c % 0x10000 / 0x100);
    rgb.z = (int)(rgb_c % 0x100);
    if (rgb.x > 255 || rgb.y > 255 || rgb.z > 255)
        printf("R: %f G: %f B: %f\n", rgb.x, rgb.y, rgb.z);
    if (brightness > strength)
        return (add_shade(rgb, brightness, strength));
    if (brightness < strength)
        return (add_tint(rgb, brightness, strength));
    return (colour);
}
