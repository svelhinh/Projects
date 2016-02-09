/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:46:23 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/09 12:00:14 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_pause(t_ray *p)
{
	mlx_string_put(p->mlx, p->win, p->sw / 2 - 25, p->sh / 2, 0xFED400,
			"PAUSE");
	mlx_string_put(p->mlx, p->win, p->sw / 2 - 45, p->sh / 2 + 30, 0xFED400,
			"R : Retry");
	mlx_string_put(p->mlx, p->win, p->sw / 2 - 90, p->sh / 2 + 60, 0xFED400,
			"M : Return to Menu");
	mlx_string_put(p->mlx, p->win, p->sw / 2 - 70, p->sh / 2 + 90, 0xFED400,
			"ESC : Quit Game");
	mlx_string_put(p->mlx, p->win, p->sw / 2 - 70, p->sh / 2 + 120, 0xFED400,
			"P : Quit Pause");
}
