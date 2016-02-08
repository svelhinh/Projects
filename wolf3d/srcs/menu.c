/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 13:18:19 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 12:37:00 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	events(int keycode, t_ray *m)
{
	if (keycode == ONE || keycode == ONE2)
		play(m);
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
			"2 : OPTIONS");
	mlx_string_put(m->mlx, m->win, SWIDTH / 2 - 50, SHEIGHT / 3 + 60, 0xffff,
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
	mlx_string_put(m->mlx, m->win, SWIDTH / 4, 50, 0xffff,
	":::       :::    ::::::::    :::        :::::::::  ::::::    :::::::::");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 8, 70, 0xffff00,
":+:       :+:   :+:    :+:   :+:        :+:             :+:  :+:     :+:");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 16, 90, 0xffff,
"+:+  +:+  +:+  +:+      +:+  +:+        +:+             +:+  +:+      +:+");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 24, 110, 0xffff00,
"+#+  +:+  +#+  +:+      +#+  +:+        +#+:+#     +:+#+:    +#+      +:+");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 32, 130, 0xffff,
"+#+  +#+  +#+  +#+      +#+  +#+        +#+             +#+  +#+      +#+");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 40, 150, 0xffff00,
"#+#  #+#  #+#   #+#    #+#   #+#        #+#             #+#  #+#     #+#");
	mlx_string_put(m->mlx, m->win, SWIDTH / 4 - 48, 170, 0xffff,
	" ##### #####     ########    #########  ###        ######    #########");
	options(m);
	mlx_key_hook(m->win, events, m);
	mlx_loop(m->mlx);
}
