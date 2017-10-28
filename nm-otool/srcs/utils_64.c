/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:14:39 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 15:21:46 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		value_len_64(uint64_t value, uint64_t base)
{
	int i;

	i = 0;
	while (value != 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

char	*ft_value_to_hex_64(uint64_t value)
{
	char		*hex;
	uint64_t	base;
	int			i;
	int			str_end;

	base = 16;
	i = value_len_64(value, base);
	str_end = i;
	if ((hex = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i--;
	while (value != 0)
	{
		if (value % base > 9)
			hex[i] = (value % base) + 87;
		else
			hex[i] = '0' + value % base;
		value /= base;
		i--;
	}
	hex[str_end] = '\0';
	return (hex);
}
