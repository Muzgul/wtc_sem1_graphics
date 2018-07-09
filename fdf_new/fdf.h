/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:15:36 by mmacdona          #+#    #+#             */
/*   Updated: 2018/07/09 10:15:38 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct      s_vector
{
	int				null;
	int				c;
	float			x;
	float			y;
	float			z;
}					ft_vector;

//Input
int     	row_count(void  **array);
char    	**add_to_array(char **array, char *row);
char    	**read_to_array(int fd);
int     	split_and_count(char *line, char c);

//Output
void		print_grid(char **grid);
void		print_vector(ft_vector v);
void		print_vgrid(ft_vector **grid);

//Vector
ft_vector   new_vector(float x, float y, float z, int null);
ft_vector   **vector_grid(char **str_arr);

//Linear
void    	shift_x(ft_vector **grid, float diff);
void    	shift_y(ft_vector **grid, float diff);
void    	shift_z(ft_vector **grid, float diff);

//Translate
void    	apply_transform(ft_vector **grid, ft_vector (*f)(ft_vector, float), float value);

//Perspective
ft_vector   to_negz(ft_vector v, float neg);
ft_vector   scale_by(ft_vector v, float size);

//Draw
int			get_color(int z_value);
void		draw_vector(ft_vector v, void *mlx_ptr, void *mlx_win);

#endif
