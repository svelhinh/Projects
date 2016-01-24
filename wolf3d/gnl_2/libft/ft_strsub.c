/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:09:19 by vtata             #+#    #+#             */
/*   Updated: 2015/11/30 19:31:29 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char		*ret;
	size_t		i;

	i = 0;
	str = (char*)s;
	ret = (char*)malloc(sizeof(*ret) * len + 1);
	if (ret == NULL || str == NULL)
		return (NULL);
	while (i < len)
		ret[i++] = str[start++];
	ret[i] = '\0';
	return (ret);
}
