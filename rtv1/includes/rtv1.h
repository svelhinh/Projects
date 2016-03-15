/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:43:55 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/15 16:56:42 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../libft/includes/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define SW 1280
# define SH 720
# define ESC /*65307*/53

typedef struct	s_vector3d
{
	float		x;
	float		y;
	float		z;
}				t_vector3d;
typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;
typedef struct	s_sphere
{
	t_vector3d	pos;
	float		radius;
	int			color;
}				t_sphere;
typedef struct	s_plane
{
	t_vector3d	pos;
	int			color;
}				t_plane;
typedef struct	s_cylinder
{
	t_vector3d	pos;
	float		height;
	float		radius;
	int			color;
}				t_cylinder;
typedef struct	s_cone
{
	t_vector3d	pos;
	float		radius;
	char		axis;
	int			color;
}				t_cone;
typedef struct	s_ray
{
	t_vector3d	start;
	t_vector3d	dir;
}				t_ray;
typedef struct	s_rt
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			endian;
	int			bpp;
	int			size_line;
	int			default_color;
	int			nbs;
	int			nbp;
	int			nbc;
	int			nbco;
	int			currentobj;
	t_sphere	*s;
	t_plane		*p;
	t_cylinder	*c;
	t_cone		*co;
	t_ray		r;
	t_vector3d	campos;
}				t_rt;
void			ft_exit(char *s);
void			mlx_pixel_put_to_image(int color, t_rt *v, int x, int y);
int				expose(t_rt *rt);
int				key_press(int keycode, t_rt *rt);
int				key_release(int keycode, t_rt *rt);
void			parsing_file(char *file, t_rt *rt);
void			render(t_rt *rt);
t_vector3d		vectorsub(t_vector3d *v1, t_vector3d *v2, int i);
float			vectordot(t_vector3d *v1, t_vector3d *v2, int i);
void			plane_init(int fd, t_rt *rt);
void			sphere_init(int fd, t_rt *rt);
void			camera_init(int fd, t_rt *rt);
void			cylinder_init(int fd, t_rt *rt);
void			init_all(char *file, t_rt *rt);
int				sphere(t_ray *r, t_sphere *s, float *t);
int				plane(t_ray *r, t_plane *p, float *t);
int				cylinder(t_ray *r, t_cylinder *c, float *t);
int				cone(t_ray *r, t_cone *co, float *t);
char			*intersect(t_rt *rt, int *currentobj, char *object);
void			line2_free(char **line2);
void			cone_init(int fd, t_rt *rt);
t_point			vectorads(t_ray *r, float t);
t_vector3d		vectordiff(t_point p, t_rt *rt, char *object, int currentobj);
#endif
