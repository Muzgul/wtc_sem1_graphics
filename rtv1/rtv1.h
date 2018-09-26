/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacdona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:05:23 by mmacdona          #+#    #+#             */
/*   Updated: 2018/08/28 14:05:28 by mmacdona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "minilibx/mlx.h"
# include <math.h>
# include "libft/libft.h"
# define min(x, y) ((x) < (y) ? (x) : (y))
# define max(x, y) ((x) > (y) ? (x) : (y))



//REMOVE THIS
#include <stdio.h>

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_cam
{
	t_vector		pos;
	t_vector		dir;
	double			fov;
}					t_cam;

typedef struct		s_m_img
{
	int				w;
	int				h;
}					t_m_img;

typedef struct		s_object
{
	char			*type;
	int				colour;
	t_vector		size;
	t_vector		origin;
	t_vector		n;
	struct s_object	*next;
}					t_object;

typedef struct		s_mat4
{
	double			a[4];
	double			b[4];
	double			c[4];
}					t_mat4;

typedef struct		s_point
{
	t_vector		o;
	t_vector		d;
}					t_point;

typedef struct		s_light
{
	t_vector		pos;
	int				brightness;
}					t_light;

typedef struct		s_holder
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_m_img			m;
	t_cam			c;
	t_object		*head;
	t_light			light;
}					t_holder;

//misc
int					check_ex(char **ex);
//init
t_point				point_get(t_vector o, t_vector d);
//angle
double				angl(double angle);
double				rev_angl(double angle);
//vector
t_vector			vect_get(float x, float y, float z);
t_vector			vect_mult(t_vector v, double s);
double				vect_dot(t_vector v1, t_vector v2);
double				vect_get_dist(t_vector f, t_vector t);
t_vector			vect_cross(t_vector v1, t_vector v2);
t_vector			vect_norm(t_vector v);
t_vector			vect_add(t_vector v1, t_vector v2);
t_vector			vect_sub(t_vector v1, t_vector v2);
//object
double				test_object(t_object *o, t_point r);
double				test_circle(int size, t_vector co, t_point r);
double				test_plane(t_point p,  t_point r);
double				test_disk(t_point p,  t_point r, int size);
double				test_cylinder(t_point p,  t_point r, t_vector size);
double				test_cone(t_point p,  t_point r, t_vector size);
//cam
t_vector			cam_ray(int x, int y, t_m_img img, t_cam c);
//free
void				free_arrstr(char **arr);
void				free_list(t_object **head);
//input_fetch
int					fetch_name(char **ex, t_object **head);
int					fetch_origin(char **ex, t_object **head, t_cam c);
int					fetch_size(char **ex, t_object **head);
int					fetch_colour(char **ex, t_object **head);
int					fetch_norm(char **ex, t_object **head);
int					fetch_vect(char *line, t_vector *v);
//read
t_object			*read_file(int fd, t_light *light, t_cam *c);
//output
void				print_list(t_object *head);
void				print_vector(t_vector v);
//mat4
t_mat4				get_mat4(void);
t_mat4				mult_mat4(t_mat4 f, t_mat4 s);
t_vector			apply_mat(t_vector og, t_mat4 m);
t_vector			add_zrotate(t_vector old, float angle);
t_vector			add_xrotate(t_vector old, float angle);
t_vector			add_yrotate(t_vector old, float angle);
//collision
double				shortest_dist(t_object *head, t_vector ro, t_vector rd, double *colour);
double				light_intensity(t_object *obj, t_vector light, t_vector ray);
//light
int					adjust_colour(int colour, double brightness, int strength);
int					key_hook(int keycode, void *param);
t_holder			setup(int fd);
void				trace(t_holder s);
void				input_error(t_object **head, char **ex, char *msg);
double				calc_res(t_vector abc);
t_object			*new_node(void);
void				add_node(t_object **head, t_object *new);
//check
int					check_name(char *line);
#endif
