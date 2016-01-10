/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:37:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/10 11:41:47 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;
typedef struct	s_xy
{
	float		xmin;
	float		ymin;
	float		xmax;
	float		ymax;
	int			color;
	float		x;
	float		y;
	float		dx;
	float		dy;
	float		m;
	int			preci;
	int			i;
	int			j;
	int			max;
	int			min;
	float		ys;
	float		xs;
	float		cx;
	float		cy;
}				t_xy;
typedef struct	s_fdf
{
	char		**split;
	int			j;
	int			i;
	int			x;
	int			y;
	int			nbn;
	char		*line;
	int			fd;
	char		**tmp;
	int			nbl;
	float		**map;
	float		zoom;
}				t_fdf;
void			put_line(t_xy c, void *mlx, void *win);
int				get_next_line(int fd, char **line);
void			ft_exit(char *s);
int				tablen(char **s);
float			**read_map(char *file, int *nbl, int *nbn);
int				key_hook(int keycode);
int				mouse_hook(int button, int x, int y);
t_xy			init_var(t_xy c, t_fdf v);
int				alti_min(float **map, int nbl, int nbn);
int				alti_max(float **map, int nbl, int nbn);
void			put_lines1(t_env e, t_fdf v, float alti);
void			put_lines2(t_env e, t_fdf v, float alti);
#endif
