/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 14:36:02 by svelhinh          #+#    #+#             */
/*   Updated: 2016/08/08 14:36:03 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int negative;

	i = 0;
	nbr = 0;
	negative = 0;
	while (str[i] != '-' && str[i] != '+' && !(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] > ' ' || ft_isascii(str[i]) == 0 || str[i] == '\0')
			return (0);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	negative = (str[i - 1] == '-');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nbr = str[i++] - '0' + nbr * 10;
	if (negative == 1)
		nbr = 0 - nbr;
	return (nbr);
}
