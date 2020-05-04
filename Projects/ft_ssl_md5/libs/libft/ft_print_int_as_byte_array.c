/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_as_byte_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:41:06 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 18:50:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_as_byte_array(unsigned int nb)
{
	int i;
	int k;
	int arr[32];

	i = -1;
	while (++i < 32)
		arr[i] = 0;
	k = 1;
	i = -1;
	while (++i < 32)
	{
		if (nb & k)
			arr[i] = 1;
		else
			arr[i] = 0;
		k = k << 1;
	}
	i = 32;
	while (--i >= 0)
	{
		ft_putnbr(arr[i]);
		if (i % 8 == 0)
			ft_putchar(' ');
	}
}
