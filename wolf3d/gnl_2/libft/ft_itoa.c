/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:22:54 by vtata             #+#    #+#             */
/*   Updated: 2015/12/07 10:55:42 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_count_char(int n)
{
	int		count_char;

	count_char = 0;
	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count_char++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		count_char++;
	}
	return (count_char);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		count_char;
	int		nb;

	nb = n;
	count_char = ft_count_char(n);
	str = (char*)malloc(sizeof(*str) * (count_char + 1));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	if (n == -2147483648)
		return (str);
	if (n < 0)
		n = -n;
	str[count_char--] = '\0';
	while (n >= 0 && count_char >= 0)
	{
		str[count_char] = (n % 10) + '0';
		n = n / 10;
		count_char--;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}
