/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:43:55 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/31 17:14:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../libft/includes/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# define ESC 53

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
typedef struct	s_rot
{
	float		x;
	float		y;
	float		z;
}				t_rot;
typedef struct	s_color
{
	float		r;
	float		g;
	float		b;
}				t_color;
typedef struct	s_light
{
	t_vector3d	pos;
	t_color		intensity;
}				t_light;
typedef struct	s_sphere
{
	t_vector3d	pos;
	float		radius;
	t_color		color;
}				t_sphere;
typedef struct	s_plane
{
	t_vector3d	norm;
	t_color		color;
	t_rot		rot;
	float		height;
}				t_plane;
typedef struct	s_cylinder
{
	t_vector3d	vec;
	t_vector3d	start;
	float		height;
	float		radius;
	t_rot		rot;
	t_color		color;
}				t_cylinder;
typedef struct	s_cone
{
	t_vector3d	pos;
	float		radius;
	t_rot		rot;
	t_color		color;
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
	int			color;
	int			w;
	int			h;
	int			background_color;
	int			nbs;
	int			nbp;
	int			nbc;
	int			nbco;
	char		*object;
	t_sphere	*s;
	t_plane		*p;
	t_cylinder	*c;
	t_cone		*co;
	t_ray		r;
	t_vector3d	campos;
	t_light		light;
	t_color		global_color;
	t_rot		rotcam;
}				t_rt;

int				key_press(int keycode, t_rt *rt);
int				expose(t_rt *rt);
void			raytracer(t_rt *rt);

/*
**	------------	INITIALISATION	-----------------------
*/
void			init_all(char *file, t_rt *rt);
void			count_objects(t_rt *rt, char *file);
void			init_sphere(t_rt *rt);
void			init_plane(t_rt *rt);
void			init_cylinder(t_rt *rt);
void			init_cone(t_rt *rt);
void			init_light(t_rt *rt);
void			init_camera(t_rt *rt);
/*
**	-------------------------------------------------------
*/


/*
**	-----------------	PARSER	---------------------------
*/
void			global_parser(char *file, t_rt *rt);
void			parsing_camera(int fd, t_rt *rt);
void			parsing_light(int fd, t_rt *rt);
void			parsing_sphere(int fd, t_rt *rt);
void			parsing_plane(int fd, t_rt *rt);
void			parsing_cylinder(int fd, t_rt *rt);
void			parsing_cone(int fd, t_rt *rt);
void			parsing_color(t_rt *rt, int j, int i, char **line2);
/*
**	-------------------------------------------------------
*/


/*
**	--------------------	ROTATIONS	--------------------
*/
void			parsing_rotations(t_rt *rt, int j, int i, char **line2);
t_vector3d		rotations(t_vector3d normal, float x, float y, float z);
/*
**	-------------------------------------------------------
*/


/*
**	--------------------	OBJECTS		--------------------
*/
int				sphere(t_ray *r, t_sphere *s);
/*
**	-------------------------------------------------------
*/


/*
**	-----------------	OTHER	---------------------------
*/
void			ft_exit(char *s);
void			mlx_pixel_put_to_image(int color, t_rt *img, int x, int y);
void			line2_free(char **line2);
void			missing_parameter(char **line2);
void			check_color(float r, float g, float b);
/*
**	-------------------------------------------------------
*/

#endif
