/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:02:56 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/10 14:25:13 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conversion_s(int *i, va_list params, int nb_char)
{
	char	*str;

	str = va_arg(params, char *);
	ft_putstr((!str) ? ("(null)") : (str));
	nb_char += (!str) ? (6) : (ft_strlen(str));
	(*i)++;
	return (nb_char);
}

int			conversion_c(int *i, va_list params, int nb_char)
{
	int	c;

	c = va_arg(params, int);
	ft_putchar(c);
	nb_char++;
	(*i)++;
	return (nb_char);
}

int			conversion_x_x_up(int *i, va_list params, int nb_char, int x)
{
	int				j;
	unsigned int	nb;
	char			*hex;

	j = 0;
	nb = va_arg(params, unsigned int);
	hex = ft_itoa_base(nb, 16);
	if (x)
		while (hex[j])
		{
			hex[j] = ft_tolower(hex[j]);
			j++;
		}
	ft_putstr(hex);
	nb_char += ft_strlen(hex);
	(*i)++;
	return (nb_char);
}

int			conversion_c_up(int *i, va_list params, int nb_char)
{
	wchar_t	wch;

	wch = va_arg(params, wchar_t);
	nb_char += ft_putwchar(wch);
	(*i)++;
	return (nb_char);
}

int			conversion_s_up(int *i, va_list params, int nb_char)
{
	wchar_t	*wstr;

	wstr = va_arg(params, wchar_t *);
	nb_char += ft_putwstr((!wstr) ? (L"(null)") : (wstr));
	(*i)++;
	return (nb_char);
}
