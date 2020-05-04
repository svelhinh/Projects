/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:17:39 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/10 14:29:02 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversions(const char *format, int *i, va_list params, int nb_char)
{
	if (format[*i + 1] == 'p')
		nb_char = conversion_p(i, params, nb_char);
	else if (format[*i + 1] == 'D')
		nb_char = conversion_d_up(i, params, nb_char);
	else if (format[*i + 1] == 'o')
		nb_char = conversion_o(i, params, nb_char);
	else if (format[*i + 1] == 'O')
		nb_char = conversion_o_up(i, params, nb_char);
	else if (format[*i + 1] == 'u')
		nb_char = conversion_u(i, params, nb_char);
	else if (format[*i + 1] == 'U')
		nb_char = conversion_u_up(i, params, nb_char);
	else if (format[*i + 1] == '%')
		nb_char = percent_escape(i, nb_char);
	return (nb_char);
}

static int	resolution(const char *format, int *i, va_list params, int nb_char)
{
	if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
		nb_char = conversion_di(i, params, nb_char);
	else if (format[*i + 1] == 's')
		nb_char = conversion_s(i, params, nb_char);
	else if (format[*i + 1] == 'S')
		nb_char = conversion_s_up(i, params, nb_char);
	else if (format[*i + 1] == 'c')
		nb_char = conversion_c(i, params, nb_char);
	else if (format[*i + 1] == 'C')
		nb_char = conversion_c_up(i, params, nb_char);
	else if (format[*i + 1] == 'X')
		nb_char = conversion_x_x_up(i, params, nb_char, 0);
	else if (format[*i + 1] == 'x')
		nb_char = conversion_x_x_up(i, params, nb_char, 1);
	else
		nb_char = conversions(format, i, params, nb_char);
	return (nb_char);
}

int			ft_printf(const char *format, ...)
{
	va_list	params;
	int		i;
	int		nb_char;

	va_start(params, format);
	i = 0;
	nb_char = 0;
	while (format[i])
	{
		if (format[i] == '%')
			nb_char = resolution(format, &i, params, nb_char);
		else
		{
			ft_putchar(format[i]);
			nb_char++;
		}
		i++;
	}
	va_end(params);
	return (nb_char);
}
