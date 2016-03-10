/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:43:55 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/10 11:19:45 by svelhinh         ###   ########.fr       */
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
typedef struct	s_sphere
{
	t_vector3d	pos;
	float		radius;
	int			color;
}				t_sphere;
typedef struct	s_plane
{
	t_vector3d	pos;
	float		dist;
	int			color;
}				t_plane;
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
	t_sphere	*s;
	t_plane		*p;
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
t_vector3d		vectorsub(t_vector3d *v1, t_vector3d *v2);
float			vectordot(t_vector3d *v1, t_vector3d *v2);
void			plane_init(int fd, t_rt *rt);
void			sphere_init(int fd, t_rt *rt);
void			camera_init(int fd, t_rt *rt);
void			init_all(char *file, t_rt *rt);
#endif
