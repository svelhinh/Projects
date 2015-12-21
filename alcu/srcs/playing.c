/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:00:45 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/21 11:12:17 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int			ft_game(char **m)
{
	t_alcu v;

	v.turn = 1;
	v.nbm = 0;
	v.winner = 2;
	while (v.winner == 2)
	{
		ft_putcolor("cyan");
		ft_display_matches(m);
		v.nbm = ft_nbmatches(m);
		if (v.turn)
			m = ft_player(m, v.nbm, &v.turn);
		else
			m = ft_ia(m, v.nbm, &v.turn);
		v.nbm = ft_nbmatches(m);
		if (v.nbm == 0)
			v.winner = v.turn;
	}
	return (v.winner);
}

char		**ft_ia(char **m, int nbm, int *turn)
{
	int	nbmr;

	nbmr = 0;
	if ((nbm % 2 == 0 && nbm % 4 != 0) || nbm == 1)
		nbmr = 1;
	else if (nbm % 2 != 0)
		nbmr = 2;
	else if (nbm % 4 == 0)
		nbmr = 3;
	if (nbm != 0)
		m = ft_remove(m, nbmr);
	*turn = 1;
	ft_putchar('\n');
	return (m);
}

char		**ft_player(char **m, int nbm, int *turn)
{
	t_alcu v;

	v.i = 0;
	v.nbmr = 0;
	while (ft_atoi(v.buf) < 1 || ft_atoi(v.buf) > 3
			|| ft_atoi(v.buf) > nbm || v.i == 0)
	{
		ft_putcolor("light blue");
		ft_putstr("\nHow many matches you want to remove ?\n");
		ft_putcolor("light yellow");
		v.ret = read(0, v.buf, BUFF_SIZE);
		v.buf[v.ret] = '\0';
		ft_putchar('\n');
		if (ft_atoi(v.buf) < 1 || ft_atoi(v.buf) > 3
				|| ft_atoi(v.buf) > nbm)
		{
			ft_putcolor("light red");
			ft_putstr("\nBAD ANSWER !!!");
		}
		v.i++;
	}
	v.nbmr = ft_atoi(v.buf);
	m = ft_remove(m, v.nbmr);
	*turn = 0;
	return (m);
}
