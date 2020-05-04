/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:37:27 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/10 13:55:11 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(long n)
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

static char		ft_negative(long *n, char c)
{
	c = '-';
	(*n == 9223372036854775807 * -1 - 1) ? (*n = 9223372036854775807) :
	(*n *= -1);
	return (c);
}

static void		conversion(long n, char *str, int *i)
{
	while (n != 0)
	{
		str[*i] = '0' + n % 10;
		n /= 10;
		(*i)--;
	}
}

char			*ft_itoa_l(long n)
{
	char	*str;
	int		i;
	int		isave;
	long	nsave;

	i = ft_nbrlen(n);
	isave = i;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	nsave = n;
	(n == 0) ? (str[0] = '0') : (0);
	(n < 0) ? (str[0] = ft_negative(&n, str[0])) : (i--);
	conversion(n, str, &i);
	if (nsave == 9223372036854775807 * -1 - 1)
	{
		str[isave] += 1;
		str[isave + 1] = '\0';
	}
	else if (nsave <= 0)
		str[isave + 1] = '\0';
	else
		str[isave] = '\0';
	return (str);
}
