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
# define TRUE 1
# define FALSE 0

typedef int			t_bool;

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
	float			w;
	t_bool			null;
}					t_vector;

typedef struct		s_matrix
{
	float			a[4];
	float			b[4];
	float			c[4];
	float			d[4];
}					t_mat4;

typedef struct		s_point
{
	t_vector		og;
	t_vector		calc;
	int				colour;
}					t_point;

typedef struct		s_mlx_obj
{
	t_point			**grid;
	void			*mlx_ptr;
	void			*mlx_win;
	t_mat4			m;
	int				width;
	int				height;
}					t_mlx_obj;

typedef struct		s_mlx_img
{
	char			*line;
	int				bpp;
	int				size_l;
	int				endian;
}					t_mlx_img;

t_point				*point_grid_row(char *line, int row);
t_point				**point_grid(char **str_arr);
int					get_color(int z_value);
void				add_pixel(t_mlx_img img, int x, int y, int color);
int					in_bounds(t_vector v, int width, int height);
void				draw_point(t_mlx_obj *o, int i, int j, t_mlx_img mlx_img);
int					draw_line(t_point v1, t_point v2, t_mlx_img mlx_img);
void				draw_grid(t_mlx_obj *o);
int					draw_horiz(t_point v1, t_point v2, t_mlx_img mlx_img);
int					draw_vert(t_point v1, t_point v2, t_mlx_img mlx_img);
int					draw_formula(t_point v1, t_point v2, t_mlx_img mlx_img);
void				free_strarr(char **strarr);
void				free_grid(t_point **grid);
int					row_count(void **array);
int					vcol_count(t_point **array);
char				**add_to_array(char **array, char *row);
char				**read_to_array(int fd);
int					split_and_count(char *line, char c);
void				print_grid(char **grid);
void				print_vector(t_vector v);
void				print_parr(t_point **grid);
t_vector			get_vector(float x, float y, float z, t_bool isnull);
t_vector			get_applied(t_vector v, t_mat4 m);
t_mat4				get_mat4(void);
t_mat4				mult_mat4(t_mat4 f, t_mat4 s);
t_vector			apply_mat(t_vector og, t_mat4 m);
t_mat4				add_zrotate(float angle);
t_mat4				add_xrotate(float angle);
t_mat4				add_yrotate(float angle);
t_mat4				add_upscale(float size);
t_mat4				add_downscale(float size);
void				shift_y(t_point **grid, float diff);
void				shift_z(t_point **grid, float diff);
void				shift_x(t_point **grid, float diff);
t_mat4				perspective_mat(float near, float far, float fov);
t_mlx_obj			*get_mlx_obj(char **strarr, int width,
								int height, float fov, char *name);
int					key_hook(int keycode, t_mlx_obj *o);

#endif
