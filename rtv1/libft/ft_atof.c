/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:13:24 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/09 14:54:09 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

static double	cnt_nb(char *s)
{
	double	nb;
	int		nb2;
	int		i;

	i = 0;
	nb2 = ft_atoi(s);
	nb = nb2;
	while (s[i])
	{
		nb /= 10;
		i++;
	}
	return (nb);
}

double			ft_atof(char *s)
{
	double	nb;
	int		i;
	char	*it;
	int		dot;

	i = 0;
	while (s[i] != '.' && s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	it = ft_strsub(s, 0, i);
	nb = ft_atoi(it);
	dot = i;
	i++;
	while (s[i] && s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	it = ft_strsub(s, dot + 1, i);
	nb += cnt_nb(it);
	return (nb);
}
