/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:58:51 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/30 13:58:52 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		angl(double angle)
{
	return (angle * (M_PI / 180));
}

double		rev_angl(double angle)
{
	return (angle / (M_PI / 180));
}
