/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:37:22 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/08 15:25:07 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

int		count_c(unsigned long value, int base)
{
	int	nb_char;

	nb_char = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		++nb_char;
		value = value / base;
	}
	return (nb_char);
}

void	reverse_str(char *str)
{
	char	tmp;
	int		i;
	int		end;

	i = 0;
	end = ft_strlen(str) - 1;
	while (end > i)
	{
		tmp = str[i];
		str[i] = str[end];
		str[end] = tmp;
		++i;
		--end;
	}
}

char	*ft_itoa_base(unsigned long value, int base)
{
	int		i;
	int		cnt;
	char	*str;
	char	*tab;

	tab = "0123456789ABCDEF";
	i = 0;
	cnt = count_c(value, base);
	if (!(str = (char*)malloc(sizeof(*str) * (cnt + 1))))
		return (NULL);
	str[cnt] = '\0';
	str[0] = '0';
	while (value > 0)
	{
		str[i++] = tab[(value % base)];
		value /= base;
	}
	reverse_str(str);
	return (str);
}
