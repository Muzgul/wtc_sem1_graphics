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

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct		s_mlx_img
{
	void			*mlx_img;
	char			*img;
	int				bpp;
	int				size_l;
	int				e;
}					t_mlx_img;

typedef struct		s_mlx_obj
{
	int				height;
	int				width;
	void			*mlx_ptr;
	void			*mlx_win;
	t_mlx_img		mlx_img;
}					t_mlx_obj;

typedef struct		s_grid
{
	int				**grid;
	int				h;
	int				w;
}					t_grid;

typedef struct		s_vector
{
	float			x;
	float			y;
}					t_vector;

typedef struct		s_cam
{
	t_vector		pos;
	t_vector		dir;
	t_vector		plane;
}					t_cam;

typedef struct		s_mat2
{
	float			a[2];
	float			b[2];
}					t_mat2;

typedef struct		s_hold
{
	t_grid			g;
	t_cam			c;
	t_mlx_obj		o;
}					t_hold;

typedef struct		s_calc
{
	t_vector		ray;
	t_vector		delta;
	t_vector		side;
	t_vector		step;
	t_vector		map;
}					t_calc;

t_cam				rotate_cam(t_cam c, float angle);
t_cam				move_cam(t_hold *hold, float dist);
int					check_pos(t_hold *h, float posx, float posy);
char				**read_to_array(int fd);
int					row_count(void **arr);
char				**add_to_array(char **array, char *row);
int					**convert_to_int(char **strarr);
void				print_strarr(char **strarr);
void				print_grid(t_grid g);
void				print_cam(t_cam c);
float				camera_dist(t_mlx_obj o, float fov);
void				free_arr(void **arr);
void				free_grid(t_grid g);
t_grid				init_grid(char **strarr);
t_vector			init_vector(float x, float y);
t_cam				init_cam(t_grid g);
t_mlx_obj			init_mlx(int height, int width);
t_vector			mat2_apply(t_vector v, t_mat2 m);
t_mat2				mat2_rotate(float angle);
float				vect_dist(t_vector v1, t_vector v2);
t_vector			vect_add(t_vector v1, t_vector v2);
t_vector			vect_rotate(t_vector v, float angle);
int					key_hook(int keycode, t_hold *hold);
void				add_pixel(t_mlx_img mlx_img, int x, int y, int color);
void				draw_col(t_mlx_obj o, int col, float dist, int side);
float				search_to(t_mlx_obj o, t_cam c, t_grid g, int col);
void				search_and_draw(t_grid g, t_cam c, t_mlx_obj o);
void				print_err(char *str);
int					close_hook(int keycode, t_hold *hold);
void				check_input(char **s);
void				init_hook(t_hold *hold);

#endif
