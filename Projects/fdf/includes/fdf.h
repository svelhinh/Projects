/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:37:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/13 10:23:53 by svelhinh         ###   ########.fr       */
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
# include "../libft/includes/libft.h"
# define RED 0
# define RED1 0x550000
# define RED2 0x770000
# define RED3 0x990000
# define RED4 0xBB0000
# define RED5 0xDD0000
# define RED6 0xFF0000
# define PINK 1
# define PINK1 0x550055
# define PINK2 0x770077
# define PINK3 0x990099
# define PINK4 0xBB00BB
# define PINK5 0xDD00DD
# define PINK6 0xFF00FF
# define BLUE 2
# define BLUE1 0x000055
# define BLUE2 0x000077
# define BLUE3 0x000099
# define BLUE4 0x0000BB
# define BLUE5 0x0000DD
# define BLUE6 0x0000FF
# define CYAN 3
# define CYAN1 0x003333
# define CYAN2 0x007777
# define CYAN3 0x009999
# define CYAN4 0x00BBBB
# define CYAN5 0x00DDDD
# define CYAN6 0x00FFFF
# define GREEN 4
# define GREEN1 0x003300
# define GREEN2 0x007700
# define GREEN3 0x009900
# define GREEN4 0x00BB00
# define GREEN5 0x00DD00
# define GREEN6 0x00FF00
# define YELLOW 5
# define YELLOW1 0x333300
# define YELLOW2 0x777700
# define YELLOW3 0x999900
# define YELLOW4 0xBBBB00
# define YELLOW5 0xDDDD00
# define YELLOW6 0xFFFF00
# define WHITE 6
# define WHITE1 0x333333
# define WHITE2 0x777777
# define WHITE3 0x999999
# define WHITE4 0xBBBBBB
# define WHITE5 0xDDDDDD
# define WHITE6 0xFFFFFF

typedef struct		s_xy
{
	float			xmin;
	float			ymin;
	float			xmax;
	float			ymax;
	int				color;
	float			x;
	float			y;
	float			dx;
	float			dy;
	float			m;
	int				preci;
	int				i;
	int				j;
	int				max;
	int				min;
	float			ys;
	float			xs;
	float			cx;
	float			cy;
	unsigned int	colorv;
}					t_xy;
typedef struct		s_fdf
{
	char			**split;
	int				j;
	int				t;
	int				i;
	int				j2;
	int				*line2;
	int				x;
	int				y;
	float			x2;
	float			y2;
	int				nbn;
	char			*line;
	int				fd;
	char			**tmp;
	int				nbl;
	float			**map;
	float			zoom;
	char			*color;
	char			**av;
	float			alti;
	float			altib;
	int				height;
	int				width;
	int				bpp;
	int				size_line;
	int				endian;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				z;
}					t_fdf;
void				put_line(t_xy c, t_fdf v);
int					get_next_line(int fd, char **line);
void				ft_exit(char *s);
int					tablen(char **s);
float				**read_map(char *file, int *nbl, int *nbn);
int					key_hook(int keycode, t_fdf *v);
int					mouse_hook(int button, int x, int y, t_fdf *v);
t_xy				init_var(t_xy c, t_fdf v);
int					alti_min(float **map, int nbl, int nbn);
int					alti_max(float **map, int nbl, int nbn);
void				put_lines1(t_fdf v);
void				put_lines2(t_fdf v);
int					color(int i2, int j2, t_xy c, t_fdf v);
int					expose_hook(t_fdf *v);
void				ft_swap(float *a, float *b);
void				commands(void);
#endif
