/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:35:51 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/10 14:36:48 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_lvl(char *lvl)
{
	int nb;

	if (!ft_strcmp(lvl, "levels/lvl1"))
		nb = 0;
	else if (!ft_strcmp(lvl, "levels/lvl2"))
		nb = 1;
	else if (!ft_strcmp(lvl, "levels/lvl3"))
		nb = 2;
	else
		nb = -1;
	return (nb);
}

void	troll(t_ray *t)
{
	if (t->map[(int)(t->posx + t->dirx * MOVE)][(int)t->posy] == -2
			|| t->map[(int)t->posx][(int)(t->posy + t->diry * MOVE)] == -2
			|| t->map[(int)(t->posx - t->dirx * MOVE)][(int)t->posy] == -2
			|| t->map[(int)t->posx][(int)(t->posy - t->diry * MOVE)] == -2)
		mlx_string_put(t->mlx, t->win, t->sw / 2 - 290, t->sh / 2, 0xff0000,
				"No this is not the exit. The exit was behind you. Retry !");
}
