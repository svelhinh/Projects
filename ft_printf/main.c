/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 10:16:46 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/10 13:38:32 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include "ft_printf.h"

int		main(void)
{
	setlocale(LC_ALL, "");
	wchar_t *yo = NULL;

	ft_putstr("ft_printf : ");
	ft_putnbrendl(ft_printf("%S\n", yo));
	ft_putstr("printf : ");
	ft_putnbrendl(printf("%S\n", yo));
	return (0);
}
