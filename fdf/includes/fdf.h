/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 09:37:59 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/30 11:06:54 by svelhinh         ###   ########.fr       */
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
	float		xmin;
	float		ymin;
	float		xmax;
	float		ymax;
	int			color;
}				t_xy;
void	yo(t_xy c, void *mlx, void *win);
#endif
