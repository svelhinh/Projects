/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:02:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/23 14:49:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
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
}				t_env;
typedef struct	s_coords
{
	float		xmin;
	float		ymin;
	float		xmax;
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
int				exit_window(int keycode);
int				expose(t_env *e);
void			put_line(t_coords c);
void			ft_swap(float *a, float *b);
void			ft_exit(char *s);
char			**parser(char *lvl);
#endif
