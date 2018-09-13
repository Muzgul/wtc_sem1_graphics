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

//angle
double				angl(double angle);
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
double				test_object(t_object *o, t_vector ro, t_vector rd);
double				test_circle(int size, t_vector co, t_vector ro, t_vector rd);
double				test_plane(t_vector po, t_vector pn,  t_vector ro, t_vector rd);
double				test_disk(t_vector po, t_vector pn, t_vector ro, t_vector rd, int size);
double				test_cylinder(t_vector po, t_vector pn, t_vector ro, t_vector rd, t_vector size);
double				test_cone(t_vector po, t_vector pn, t_vector ro, t_vector rd, t_vector size);
//cam
t_vector			cam_ray(int x, int y, t_m_img img, t_cam c);
//free
void				free_arrstr(char **arr);
void				free_list(t_object **head);
//input_fetch
int					fetch_name(t_object *node, char *line);
int					fetch_origin(t_object *node, char **ex);
int					fetch_size(t_object *node, char **ex);
int					fetch_colour(t_object *node, char **ex);
int					fetch_norm(t_object *node, char **ex);
//read
t_object			*read_objects(int fd);
//output
void				print_list(t_object *head);
void				print_vector(t_vector v);
//mat4
t_mat4				get_mat4(void);
t_mat4				mult_mat4(t_mat4 f, t_mat4 s);
t_vector			apply_mat(t_vector og, t_mat4 m);
t_mat4				add_zrotate(float angle);
t_mat4				add_xrotate(float angle);
t_mat4				add_yrotate(float angle);

#endif
