/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:43:55 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/02 18:52:58 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../libft/includes/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# define SW 320
# define SH 200
# define ESC /*65307*/53

typedef struct	s_vector3d
{
	float		x;
	float		y;
	float		z;
}				t_vector3d;
typedef struct	s_coords
{
	int			x;
	int			y;
	int			color;
}				t_coords;
typedef struct	s_rt
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			endian;
	int			bpp;
	int			size_line;
	t_vector3d	vdir;
	t_vector3d	campos;
	t_vector3d	sphere;
	float		sphereradius;
}				t_rt;
void			ft_exit(char *s);
void			mlx_pixel_put_to_image(t_coords *c, t_rt *v, int x, int y);
int				expose(t_rt *rt);
int				key_press(int keycode, t_rt *rt);
int				key_release(int keycode, t_rt *rt);
void			parsing_file(char *file, t_rt *rt);
void			render(t_rt *rt);
#endif
