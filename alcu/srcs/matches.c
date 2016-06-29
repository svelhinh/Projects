/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matches.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:07:40 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/21 13:20:13 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	ft_display_matches(char **m)
{
	int		i;
	int		matches;
	int		nbspaces;

	i = 0;
	while (m[i])
	{
		matches = 0;
		nbspaces = 0;
		while (nbspaces < i)
		{
			ft_putchar(' ');
			nbspaces++;
		}
		while (matches < ft_atoi(m[i]))
		{
			ft_putchar('|');
			matches++;
		}
		if (ft_strcmp(m[i], "0"))
			ft_putchar('\n');
		i++;
	}
}

char	**ft_remove(char **m, int nbmr)
{
	int i;

	i = 0;
	while (m[i] && ft_strcmp(m[i], "0"))
		i++;
	i--;
	while (nbmr)
	{
		if (ft_atoi(m[i]) <= 0)
			i--;
		m[i] = ft_itoa(ft_atoi(m[i]) - 1);
		nbmr--;
	}
	return (m);
}

int		ft_nbmatches(char **m)
{
	int i;
	int nbm;

	i = 0;
	nbm = 0;
	while (m[i])
	{
		nbm += ft_atoi(m[i]);
		i++;
	}
	return (nbm);
}
