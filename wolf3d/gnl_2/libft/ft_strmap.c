/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 22:17:25 by vtata             #+#    #+#             */
/*   Updated: 2015/12/03 16:23:38 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (s && f)
	{
		str = (char*)malloc(sizeof(*str) * (ft_strlen(s) + 1));
		if (str == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
