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
# include <math.h>
# include "minilibx/mlx.h"

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
	float			plane;
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

// input
char		**read_to_array(int fd);
int			row_count(void **arr);
char		**add_to_array(char **array, char *row);
int			**convert_to_int(char **strarr);
// output
void		print_strarr(char **strarr);
void		print_grid(t_grid g);
void		print_cam(t_cam c);
//perspective
float		camera_dist(t_mlx_obj o, float fov);
//free
void		free_arr(void **arr);
void		free_grid(t_grid g);
//init
t_grid		init_grid(char **strarr);
t_vector	init_vector(float x, float y);
t_cam		init_cam(t_grid g, float fov);
t_mlx_obj	init_mlx(int height, int width);
//matrix
t_vector	mat2_apply(t_vector v, t_mat2 m);
t_mat2		mat2_rotate(float angle);
//vect
float		vect_dist(t_vector v1, t_vector v2);
t_vector	vect_add(t_vector v1, t_vector v2);
t_vector	vect_rotate(t_vector v, float angle);
//cam
float		cam_plane(t_cam c, float fov);
t_cam		rotate_cam(t_cam c, float angle);

#endif
