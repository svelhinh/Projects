/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:36:19 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/10 14:36:21 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(const char *str, int str_base)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			result = result * str_base + ((str[i] - 'a') + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result * str_base + ((str[i] - 'A') + 10);
		else
			result = result * str_base + (str[i] - '0');
		++i;
	}
	return (result);
}
