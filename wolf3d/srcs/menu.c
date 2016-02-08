/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 13:18:19 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/08 15:00:03 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	events(int keycode, t_ray *m)
{
	if (keycode == ONE || keycode == ONE2)
		play(m);
	if (keycode == TWO || keycode == TWO2)
		options(m);
	if (keycode == ESC)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(0);
	}
	return (0);
}

static void	menus(t_ray *m)
{
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 40, m->sh / 2, 0xffff,
			"1 : PLAY");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 55, m->sh / 2 + 30, 0xffff,
			"2 : OPTIONS");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 50, m->sh / 2 + 60, 0xffff,
			"ESC : EXIT");
}

void		principal_menu(t_ray *m, int i)
{
	(i == 0) ? (m->win = mlx_new_window(m->mlx, m->sw, m->sh,
				"Menu Principal")) : (ft_empty(m, i));
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 350, 50, 0xffff,
":::       :::    ::::::::    :::        :::::::::  ::::::    :::::::::");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 350, 70, 0xffff00,
":+:       :+:   :+:    :+:   :+:        :+:             :+:  :+:     :+:");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 350, 90, 0xffff,
"+:+  +:+  +:+  +:+      +:+  +:+        +:+             +:+  +:+      +:+");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 350, 110, 0xffff00,
"+#+  +:+  +#+  +:+      +#+  +:+        +#+:+#     +:+#+:    +#+      +:+");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 350, 130, 0xffff,
"+#+  +#+  +#+  +#+      +#+  +#+        +#+             +#+  +#+      +#+");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 350, 150, 0xffff00,
"#+#  #+#  #+#   #+#    #+#   #+#        #+#             #+#  #+#     #+#");
	mlx_string_put(m->mlx, m->win, m->sw / 2 - 350, 170, 0xffff,
" ##### #####     ########    #########  ###        ######    #########");
	menus(m);
	mlx_key_hook(m->win, events, m);
	mlx_loop(m->mlx);
}
