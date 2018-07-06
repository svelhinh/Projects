/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:02:56 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/10 14:25:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conversion_p(int *i, va_list params, int nb_char)
{
	void	*addr;
	char	*hex;
	int		j;

	j = 0;
	addr = va_arg(params, void *);
	hex = ft_itoa_base((unsigned long)addr, 16);
	while (hex[j])
	{
		hex[j] = ft_tolower(hex[j]);
		j++;
	}
	ft_putstr("0x");
	ft_putstr(hex);
	nb_char += 2 + ft_strlen(hex);
	(*i)++;
	return (nb_char);
}

int			conversion_o(int *i, va_list params, int nb_char)
{
	int		nb;
	char	*oct;

	nb = va_arg(params, int);
	oct = ft_itoa_base(nb, 8);
	ft_putstr(oct);
	nb_char += ft_strlen(oct);
	(*i)++;
	return (nb_char);
}

int			conversion_o_up(int *i, va_list params, int nb_char)
{
	long	nb;
	char	*oct;

	nb = va_arg(params, long);
	oct = ft_itoa_base(nb, 8);
	ft_putstr(oct);
	nb_char += ft_strlen(oct);
	(*i)++;
	return (nb_char);
}
