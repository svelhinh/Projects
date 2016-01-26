/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:02:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/26 14:26:54 by svelhinh         ###   ########.fr       */
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
	double		x;
	double		ymin;
	double		ymax;
	double		dx;
	double		dy;
	double		m;
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
	double	cameraX;
	double	rayPosX;
	double	rayPosY;
	double	rayDirX;
	double	rayDirY;
	double	distMurX;
	double	distMurY;
	double	dist2MurX;
	double	dist2MurY;
	double	longueurMur;
	int		mapX;
	int		mapY;
	int		x;
	int		etapeX;
	int		etapeY;
	int		touche;
	int		murVertiOuHori;
	int		hauteurMur;
	int		drawStart;
	int		drawEnd;
	int		color;
	int		y;
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
