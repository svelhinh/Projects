/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 11:49:48 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/24 14:51:14 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*cpy_line(int *tab)
{
	int	*line;
	int	i;

	i = 0;
	if (!(line = (int *)malloc(sizeof(int) * 5)))
		ft_exit("Le malloc de line dans define_color() a echoue");
	while (i < 5)
	{
		line[i] = tab[i];
		i++;
	}
	return (line);
}

int		colorcmp(char *color)
{
	int	j;

	j = WHITE;
	(!ft_strcmp(color, "red")) ? (j = RED) : (0);
	(!ft_strcmp(color, "pink")) ? (j = PINK) : (0);
	(!ft_strcmp(color, "blue")) ? (j = BLUE) : (0);
	(!ft_strcmp(color, "cyan")) ? (j = CYAN) : (0);
	(!ft_strcmp(color, "green")) ? (j = GREEN) : (0);
	(!ft_strcmp(color, "yellow")) ? (j = YELLOW) : (0);
	(!ft_strcmp(color, "white")) ? (j = WHITE) : (0);
	return (j);
}

int		*define_color(char *color, int m)
{
	static int	**tab;
	t_fdf		v;

	v.t = 0;
	if (!tab)
	{
		if (!(tab = (int **)malloc(sizeof(int *) * 7)))
			ft_exit("Le malloc de tab dans define_color() a echoue");
		while (++v.t < 7)
			if (!(tab[++v.t] = (int *)malloc(sizeof(int) * 5)))
				ft_exit("Le malloc de tab[t] dans define_color() a echoue");
		tab[0] = (int[5]){RED1, RED2, RED3, RED4, RED5};
		tab[1] = (int[5]){PINK1, PINK2, PINK3, PINK4, PINK5};
		tab[2] = (int[5]){BLUE1, BLUE2, BLUE3, BLUE4, BLUE5};
		tab[3] = (int[5]){CYAN1, CYAN2, CYAN3, CYAN4, CYAN5};
		tab[4] = (int[5]){GREEN1, GREEN2, GREEN3, GREEN4, GREEN5};
		tab[5] = (int[5]){YELLOW1, YELLOW2, YELLOW3, YELLOW4, YELLOW5};
		tab[6] = (int[5]){WHITE1, WHITE2, WHITE3, WHITE4, WHITE5};
	}
	v.j2 = colorcmp(color);
	v.line2 = cpy_line(tab[v.j2]);
	if (m == 1)
		free(tab);
	return (v.line2);
}

int		**define_tab(t_fdf v)
{
	int	j;
	int	**tab;

	j = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * 5)))
		ft_exit("Le malloc de tab dans color() a echoue");
	while (j < 5)
	{
		if (!(tab[j] = (int *)malloc(sizeof(int) * 5)))
			ft_exit("Le malloc de tab[j] dans color() a echoue");
		j++;
	}
	tab[0] = define_color(v.av[2], 0);
	tab[1] = define_color(v.av[3], 0);
	tab[2] = define_color(v.av[4], 0);
	tab[3] = define_color(v.av[5], 0);
	tab[4] = define_color(v.av[6], 1);
	return (tab);
}

int		color(int i2, int j2, t_xy c, t_fdf v)
{
	static int	**tab;

	if (!tab)
		tab = define_tab(v);
	if (v.map[c.j][c.i] <= c.min)
		c.color = tab[0][0];
	if ((v.map[c.j][c.i] > c.min && v.map[c.j][c.i] <= c.max / 4)
			|| (v.map[c.j + j2][c.i + i2] > c.min
				&& v.map[c.j + j2][c.i + i2] <= c.max / 4))
		c.color = tab[1][1];
	if ((v.map[c.j][c.i] > c.max / 4 && v.map[c.j][c.i] <= c.max / 2)
			|| (v.map[c.j + j2][c.i + i2] > c.max / 4
				&& v.map[c.j + j2][c.i + i2] <= c.max / 2))
		c.color = tab[2][2];
	if ((v.map[c.j][c.i] > c.max / 2 && v.map[c.j][c.i] <= 3 * c.max / 4)
			|| (v.map[c.j + j2][c.i + i2] > c.max / 2
				&& v.map[c.j + j2][c.i + i2] <= 3 * c.max / 4))
		c.color = tab[3][3];
	if ((v.map[c.j][c.i] > 3 * c.max / 4 && v.map[c.j][c.i] <= c.max)
			|| (v.map[c.j + j2][c.i + i2] > 3 * c.max / 4
				&& v.map[c.j + j2][c.i + i2] <= c.max))
		c.color = tab[4][4];
	return (c.color);
}
