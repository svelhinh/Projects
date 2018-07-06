/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:34:48 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/10 14:05:48 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);

/*
**	------------------		CONVERSIONS		-------------------------
*/
int	conversion_di(int *i, va_list params, int nb_char);
int	conversion_d_up(int *i, va_list params, int nb_char);
int	conversion_s(int *i, va_list params, int nb_char);
int	conversion_c(int *i, va_list params, int nb_char);
int	conversion_c_up(int *i, va_list params, int nb_char);
int	conversion_x_x_up(int *i, va_list params, int nb_char, int x);
int	conversion_p(int *i, va_list params, int nb_char);
int	conversion_o(int *i, va_list params, int nb_char);
int	conversion_o_up(int *i, va_list params, int nb_char);
int	conversion_u(int *i, va_list params, int nb_char);
int	conversion_u_up(int *i, va_list params, int nb_char);
int	conversion_s_up(int *i, va_list params, int nb_char);
/*
**	-----------------------------------------------------------------
*/
/*
**	------------------		OTHER		-------------------------
*/
int	percent_escape(int *i, int nb_char);
/*
**	-----------------------------------------------------------------
*/

#endif
