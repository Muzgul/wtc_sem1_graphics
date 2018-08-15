/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:57:58 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/15 15:57:59 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_H
# define FT_WOLF_H
# define NULL (void *)0

# include "libft/libft.h"

// input
char	**read_to_array(int fd);
int		row_count(void **arr);
char	**add_to_array(char **array, char *row);
// output
void	print_strarr(char **strarr);


#endif
