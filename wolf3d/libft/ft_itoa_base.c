/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 21:47:57 by vtata             #+#    #+#             */
/*   Updated: 2016/01/29 15:46:08 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

int		count_c(int value, int base)
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

char	*ft_itoa_base(int value, int base)
{
	int 	result;
	int		i;
	char	*str;
	char	tab[] = "0123456789ABCDEF";

	result = 0;
	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (count_c(value, base) + 1))))
		return (NULL);
	str[count_c(value, base)] = '\0';
	str[0] = '0';
	while (value > 0)
	{
		str[i++] = tab[(value % base)];
		value = value / base;
	}
	reverse_str(str);
	return (str);
}
