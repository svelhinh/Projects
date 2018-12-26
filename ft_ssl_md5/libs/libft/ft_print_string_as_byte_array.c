/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_as_byte_array.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:41:06 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 18:49:55 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_string_as_byte_array(unsigned char *str, unsigned int len)
{
	int				i;
	unsigned int	k;

	k = 0;
	while (k < len)
	{
		i = 7;
		while (i >= 0)
		{
			(*str & 1 << i) ? ft_putchar('1') : ft_putchar('0');
			i--;
		}
		ft_putchar(' ');
		str++;
		k++;
	}
}
