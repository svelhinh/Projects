/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:37:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/03 15:19:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
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
}				t_fdf;
void			put_line(t_xy c, void *mlx, void *win);
int				get_next_line(int fd, char **line);
void			ft_exit(char *s);
int				tablen(char **s);
int				**read_map(char *file, int *nbl, int *nbn);
int				key_hook(int keycode);
int				mouse_hook(int button, int x, int y);
#endif
