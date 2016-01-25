/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:02:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/25 15:49:57 by svelhinh         ###   ########.fr       */
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
# define SWIDTH 1000
# define SHEIGHT 1000

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*lvl;
	int			**map;
}				t_env;
typedef struct	s_coords
{
	float		x;
	float		ymin;
	float		ymax;
	float		dx;
	float		dy;
	float		m;
	char		*data;
	int			color;
	int			size_line;
	int			bpp;
	int			endian;
}				t_coords;
typedef struct	s_ray
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		x;
	int		y;
	int		color;
	double	cameraX;
	double	rayPosX;
	double	rayPosY;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	deltaDistX;
	double	deltaDistY;
	int		hit;
	int		stepX;
	int		stepY;
	double	sideDistX;
	double	sideDistY;
	int		side;
	double	perpWallDist;
	double	lineHeight;
	double	drawStart;
	double	drawEnd;
}				t_ray;
int				exit_window(int keycode);
int				expose(t_env *e);
void			line_verti(t_coords c, t_env e);
void			ft_swap(float *a, float *b);
void			ft_exit(char *s);
int				**parser(char *lvl);
void			raycasting(t_env e);
int				move(int keycode, t_ray *r);
#endif
