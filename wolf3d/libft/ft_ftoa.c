/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:00:58 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/09 19:26:47 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <math.h>

static int		ft_nbrlen(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ft_itoa_d(int n)
{
	char	*str;
	int		i;
	int		isave;

	i = ft_nbrlen(n);
	isave = i;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	while (n > 0)
	{
		str[i] = '0' + n % 10;
		ft_putendl(str);
		n /= 10;
		i--;
	}
	str[isave + 1] = '\0';
	return (str);
}

char			*ft_ftoa(double n, int preci)
{
	char	*str;
	int		i;
	int		ipart;
	double	fpart;

	i = 0;
	ipart = (int)n;
	fpart = n - (double)ipart;
	str = ft_strdup(ft_itoa(ipart));
	str = ft_strjoin(str, ".");
	while (i < preci)
	{
		fpart = fpart * 10;
		i++;
	}
	i = 0;
	while (i < preci - ft_nbrlen(fpart))
	{
		str = ft_strjoin(str, "0");
		i++;
	}
	fpart++;
	str = ft_strjoin(str, ft_itoa_d(fpart));
	return (str);
}
