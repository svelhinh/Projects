/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:02:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/27 18:14:39 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../gnl/get_next_line.h"
# define SWIDTH 2500//1180
# define SHEIGHT 1300//924
# define ROT 0.1
# define MOVE 0.3
# define SKY 0x7FD1EF
# define FLOOR 0xaaaaaa
# define FRONT 0x000051
# define BACK 0x000073
# define RIGHT 0x001095
# define LEFT 0x023097

typedef struct	s_coords
{
	double		x;
	double		ymin;
	double		ymax;
	double		dx;
	double		dy;
	double		m;
	int			color;
}				t_coords;
typedef struct	s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		distmurx;
	double		distmury;
	double		dist2murx;
	double		dist2mury;
	double		longueurmur;
	int			mapx;
	int			mapy;
	int			x;
	int			etapex;
	int			etapey;
	int			touche;
	int			mur;
	int			hauteurmur;
	int			drawstart;
	int			drawend;
	void		*mlx;
	void		*win;
	void		*img;
	char		*lvl;
	int			**map;
	int			i;
	char		*data;
	int			size_line;
	int			bpp;
	int			endian;
}				t_ray;
//int				exit_window(int keycode, t_ray *r);
int				key(int keycode, t_ray *r);
int				expose(t_ray *r);
void			ft_swap(float *a, float *b);
void			ft_exit(char *s);
int				**parser(char *lvl);
void			raycasting(t_ray *r);
void			init_var(t_ray *r);
void			put_line(t_ray r);
void			put_floor_sky(t_ray r);
#endif
