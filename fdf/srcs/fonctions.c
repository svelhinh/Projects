/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 10:48:31 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/10 11:35:17 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *s)
{
	perror(s);
	exit(0);
}

int		tablen(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_xy	init_var(t_xy c, t_fdf v)
{
	c.j = 0;
	c.i = 0;
	c.y = 100;
	c.x = 1100;
	c.ys = c.y;
	c.xs = c.x;
	c.cx = 50 * v.zoom;
	c.cy = 25 * v.zoom;
	c.min = alti_min(v.map, v.nbl, v.nbn);
	c.max = alti_max(v.map, v.nbl, v.nbn) - c.min;
	return (c);
}

