/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:38:59 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/10 14:08:41 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	three_or_more_bytes(wchar_t c)
{
	unsigned char	byte;

	if (c <= 0xffff)
	{
		byte = (c >> 12) + 0xe0;
		write(1, &byte, 1);
		byte = ((c >> 6) & 0x3f) + 0x80;
		write(1, &byte, 1);
		byte = (c & 0x3f) + 0x80;
		write(1, &byte, 1);
		return (3);
	}
	else
	{
		byte = (c >> 18) + 0xf0;
		write(1, &byte, 1);
		byte = ((c >> 12) & 0x3f) + 0x80;
		write(1, &byte, 1);
		byte = ((c >> 6) & 0x3f) + 0x80;
		write(1, &byte, 1);
		byte = (c & 0x3f) + 0x80;
		write(1, &byte, 1);
		return (4);
	}
}

int			ft_putwchar(wchar_t c)
{
	unsigned char	byte;

	if (c <= 0x7f)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c <= 0x7ff)
	{
		byte = (c >> 6) + 0xc0;
		write(1, &byte, 1);
		byte = (c & 0x3f) + 0x80;
		write(1, &byte, 1);
		return (2);
	}
	else
		return (three_or_more_bytes(c));
}
