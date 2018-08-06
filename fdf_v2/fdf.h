/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:47:18 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/04 11:47:20 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef int ft_bool;
#define true 1
#define false 0

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
	float			w;
	ft_bool			null;
}					ft_vector;

typedef struct		s_matrix
{
	float			a[4];
	float			b[4];
	float			c[4];
	float			d[4];
}					ft_mat4;

typedef struct		s_point
{
	ft_vector		og;
	ft_vector		calc;
	int				colour;
}					ft_point;

typedef struct		s_mlx_obj
{
	ft_point		**grid;
	void			*mlx_ptr;
	void			*mlx_win;
	ft_mat4			m;
	int				width;
	int				height;
}					ft_mlx_obj;

//input.c
int     		row_count(void  **array);
int				vcol_count(ft_point **array);
char    		**add_to_array(char **array, char *row);
char    		**read_to_array(int fd);
int     		split_and_count(char *line, char c);

//convert.c
ft_point		*point_grid_row(char *line, int row);
ft_point		**point_grid(char **str_arr);

//output.c
void			print_grid(char **grid);
void			print_vector(ft_vector v);
void			print_pArr(ft_point **grid);

//vector.c
ft_vector       get_vector(float x, float y, float z, ft_bool isnull);
ft_vector       get_applied(ft_vector v, ft_mat4 m);

//mat4.c
ft_mat4     	get_mat4();
ft_mat4     	mult_mat4(ft_mat4 f, ft_mat4 s);
ft_vector		apply_mat(ft_vector og, ft_mat4 m);

//t_mat4.c
ft_mat4     	add_zrotate(float angle);
ft_mat4     	add_xrotate(float angle);
ft_mat4     	add_yrotate(float angle);

//linear
void    		shift_y(ft_point **grid, float diff);
void    		shift_z(ft_point **grid, float diff);
void    		shift_x(ft_point **grid, float diff);

//perspective.c
ft_mat4     	perspective_mat(float near, float far, float fov);

//draw.c
int				get_color(int z_value);
void			draw_vector(ft_point v, void *mlx_ptr, void *mlx_win);
void			draw_grid(ft_mlx_obj *o);
//In Vector
int				draw_line(ft_point v1, ft_point v2, void *mlx_ptr, void *mlx_win);

//init.c
ft_mlx_obj      *get_mlx_obj(char **strarr, int width, int height, float fov);

//keyhook.c
int     		key_hook(int keycode, ft_mlx_obj *o);

#endif