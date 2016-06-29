/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 10:48:31 by svelhinh          #+#    #+#             */
/*   Updated: 2016/06/29 10:25:19 by svelhinh         ###   ########.fr       */
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

void	init_var(t_xy *c, t_fdf v)
{
	c->j = 0;
	c->i = 0;
	c->y = v.y2;
	c->x = v.x2;
	c->ys = c->y;
	c->xs = c->x;
	c->cx = 50 * v.zoom;
	c->cy = 25 * v.zoom;
	c->min = alti_min(v.map, v.nbl, v.nbn);
	c->max = alti_max(v.map, v.nbl, v.nbn);
}

void	ft_swap(float *a, float *b)
{
	float c;

	c = *a;
	*a = *b;
	*b = c;
}

void	commands(void)
{
	char *line;

	ft_putcolor("cyan");
	ft_putstr("Press the directionnal keys to move the map\nMove the mouse ");
	ft_putstr("wheel to zoom in or zoom out\nPress right Shift or right Ctrl ");
	ft_putstr("to zoom in or zoom out twice\nPress U or J to increase or ");
	ft_putstr("decrease the altitude\nPress left Shift or left Ctrl to ");
	ft_putstr("increase or decrease twice the altitude\nClick with the mouse ");
	ft_putstr("to move the map to the location of the cursor\n");
	ft_putstr("Press Enter to continue...\n");
	get_next_line(0, &line);
	ft_putchar('\n');
	while (line[0] != '\0')
	{
		ft_putstr("Press Enter to continue...\n");
		get_next_line(0, &line);
		ft_putchar('\n');
	}
	ft_putcolor("white");
}
