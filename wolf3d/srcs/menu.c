/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 13:18:19 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/06 17:54:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	play(int keycode, t_ray *m)
{
	if (keycode == ONE || keycode == ONE2)
	{
		mlx_destroy_window(m->mlx, m->win);
		main2(*m);
	}
	if (keycode == ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(0);
	}
	return (0);
}

static void	options(t_ray *m)
{
	mlx_string_put(m->mlx, m->win, SWIDTH / 2 - 40, SHEIGHT / 3, 0xffff,
			"1 : PLAY");
	mlx_string_put(m->mlx, m->win, SWIDTH / 2 - 50, SHEIGHT / 3 + 30, 0xffff,
			"ESC : EXIT");
}

/*static void	bkgd(t_ray *m)
{
	int		x;
	int		y;
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(m->mlx, "textures/stone.xpm", &w, &h);
	y = 0;
	while (y < SHEIGHT)
	{
		x = 0;
		while (x < SWIDTH)
		{
			mlx_put_image_to_window(m->mlx, m->win, img, x, y);
			x += w;
		}
		y += h;
	}
}*/

void		menu(t_ray *m)
{
	m->win = mlx_new_window(m->mlx, SWIDTH, SHEIGHT, "Menu Principal");
	//bkgd(m);
	mlx_string_put(m->mlx, m->win, SWIDTH / 4, 50, 0x9999,
	":::       :::   :::::::::    :::        :::::::::  ::::::    :::::::::");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 8, 70, 0xaaaa00,
":+:       :+:   :+:    :+:   :+:        :+:             :+:  :+:     :+:");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 16, 90, 0xbbbb,
"+:+  +:+  +:+  +:+      +:+  +:+        +:+             +:+  +:+      +:+");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 24, 110, 0xcccc00,
"+#+  +:+  +#+  +:+      +#+  +:+        +#+:+#     +:+#+:    +#+      +:+");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 32, 130, 0xdddd,
"+#+  +#+  +#+  +#+      +#+  +#+        +#+             +#+  +#+      +#+");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 40, 150, 0xeeee00,
"#+#  #+#  #+#   #+#    #+#   #+#        #+#             #+#  #+#     #+#");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 48, 170, 0xffff,
	" ##### #####     #########    #########  ###        ######    #########");
	options(m);
	mlx_key_hook(m->win, play, m);
	mlx_loop(m->mlx);
}
