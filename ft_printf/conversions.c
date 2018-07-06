/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:02:56 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/10 14:24:49 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_nb(int nb)
{
	int i;

	i = (nb <= 0) ? (1) : (0);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int			conversion_di(int *i, va_list params, int nb_char)
{
	int	nb;

	nb = va_arg(params, int);
	ft_putnbr(nb);
	nb_char += count_nb(nb);
	(*i)++;
	return (nb_char);
}

int			conversion_u(int *i, va_list params, int nb_char)
{
	unsigned int	nb;
	char			*unb;

	nb = va_arg(params, unsigned int);
	unb = ft_itoa_l(nb);
	ft_putstr(unb);
	nb_char += ft_strlen(unb);
	(*i)++;
	return (nb_char);
}

int			conversion_u_up(int *i, va_list params, int nb_char)
{
	unsigned long	nb;
	char			*unb;

	nb = va_arg(params, unsigned long);
	unb = ft_itoa_base(nb, 10);
	ft_putstr(unb);
	nb_char += ft_strlen(unb);
	(*i)++;
	return (nb_char);
}

int			conversion_d_up(int *i, va_list params, int nb_char)
{
	long	nb;
	char	*str;

	nb = va_arg(params, long);
	str = ft_itoa_l(nb);
	ft_putstr(str);
	nb_char += ft_strlen(str);
	(*i)++;
	return (nb_char);
}
