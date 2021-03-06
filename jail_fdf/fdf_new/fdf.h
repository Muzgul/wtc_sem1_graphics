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
# include <math.h>

//DONT NEED
#include <stdio.h>

typedef struct      s_vector
{
	int				null;
	int				c;
	float			x;
	float			y;
	float			z;
	float			w;
}					ft_vector;

typedef struct		s_matrix
{
	float			a[4];
	float			b[4];
	float			c[4];
	float			d[4];
}					ft_mat4;

//Input
int     	row_count(void  **array);
int			vcol_count(ft_vector **array);
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
void		apply_matrix(ft_vector **grid, ft_mat4 m);
ft_vector	matrix_vector(ft_vector v, ft_mat4 m);

//Perspective
ft_vector   to_negz(ft_vector v, float neg);
ft_vector   scale_by(ft_vector v, float size);
ft_vector   for_vector(ft_vector v);
void    	apply_perspective(ft_vector **grid);

//Draw
int			get_color(int z_value);
void		draw_vector(ft_vector v, void *mlx_ptr, void *mlx_win);
int			draw_line(ft_vector v1, ft_vector v2, void *mlx_ptr, void *mlx_win);

//Matrix
ft_mat4     new_matrix();
ft_mat4     add_perspective(ft_mat4 old, float near, float far, float fov, float aspect);
ft_mat4     add_xrotate(ft_mat4 old, float angle);
ft_mat4     add_yrotate(ft_mat4 old, float angle);
ft_mat4     add_zrotate(ft_mat4 old, float angle);

#endif
