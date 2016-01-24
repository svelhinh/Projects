/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <vtata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:54:59 by vtata             #+#    #+#             */
/*   Updated: 2015/12/07 13:48:09 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void	ft_init(size_t *i, int *j, int *retry)
{
	*i = 0;
	*j = 0;
	*retry = 0;
}

static char	*ft_check_s2(char *ret, const char *s1, const char *s2, size_t *i)
{
	if (s2[0] == '\0')
		ret = (char*)(s1 + *i);
	else
		ret = NULL;
	return (ret);
}

static char	*ft_mark_letter(const char *s1, const char *s2, size_t *i, int *j)
{
	char *str;

	while (s1[*i] != s2[*j] && s1[*i] != '\0')
		*i = *i + 1;
	str = (char*)(s1 + *i);
	return (str);
}

static void	ft_increment(size_t *i, int *j)
{
	*i = *i + 1;
	*j = *j + 1;
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		retry;
	char	*str;

	str = NULL;
	ft_init(&i, &j, &retry);
	if (s2[0] == '\0')
		return (ft_check_s2(str, s1, s2, &i));
	while (s1[i] != '\0' && i < n)
	{
		str = ft_mark_letter(s1, s2, &i, &j);
		while (s1[i] == s2[j] && i < n)
		{
			ft_increment(&i, &j);
			if (s2[j] == '\0')
				return (str);
		}
		j = 0;
		i = retry++;
	}
	return (NULL);
}
