/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:37:59 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/28 10:52:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;
typedef struct	s_xy
{
	int			xmin;
	int			ymin;
	int			xmax;
	int			ymax;
	int			x;
	int			y;
	int			color;
}				t_xy;
void			xline(t_xy c, void *mlx, void *win);
void			yline(t_xy c, void *mlx, void *wini);
#endif
