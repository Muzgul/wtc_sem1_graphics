/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:50:30 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/27 10:50:31 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			check_len(char *s, int len)
{
	char	**ex;
	int		cnt;

	ex = ft_strsplit(s, ' ');
	cnt = row_count((void **)ex);
	if (len == -1)
		return (cnt);
	return (len - cnt);
}

void		check_input(char **s)
{
	int		i;
	int		j;
	size_t	len;

	if (s == NULL)
		print_err("Invalid map!");
	len = check_len(s[0], -1);
	i = 0;
	while (s[i] != NULL)
	{
		if (check_len(s[i], len) != 0)
			print_err("Invalid map!");
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] != ' ' && s[i][j] != '-' && ft_isdigit(s[i][j]) == 0)
				print_err("Invalid map!");
			j++;
		}
		i++;
	}
	if (i == 0)
		print_err("Invalid map!");
}
