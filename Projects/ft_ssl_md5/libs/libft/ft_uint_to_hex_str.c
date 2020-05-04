/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_to_hex_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:45:33 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 19:00:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_hex(char (*hex)[16])
{
	(*hex)[0] = '0';
	(*hex)[1] = '1';
	(*hex)[2] = '2';
	(*hex)[3] = '3';
	(*hex)[4] = '4';
	(*hex)[5] = '5';
	(*hex)[6] = '6';
	(*hex)[7] = '7';
	(*hex)[8] = '8';
	(*hex)[9] = '9';
	(*hex)[10] = 'a';
	(*hex)[11] = 'b';
	(*hex)[12] = 'c';
	(*hex)[13] = 'd';
	(*hex)[14] = 'e';
	(*hex)[15] = 'f';
}

void		ft_uint_to_hex_str(unsigned int num, unsigned char *buf)
{
	int		len;
	int		k;
	char	hex[16];

	init_hex(&hex);
	len = 0;
	k = 0;
	while (num != 0)
	{
		buf[len] = hex[num & 0xF];
		len++;
		num >>= 4;
	}
	if (len < 8)
		buf[len++] = '0';
	while (k < len / 2)
	{
		buf[k] ^= buf[len - k - 1];
		buf[len - k - 1] ^= buf[k];
		buf[k] ^= buf[len - k - 1];
		k++;
	}
	buf[len] = '\0';
}
