/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:13:11 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/21 13:30:05 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		ft_check(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i]) && tmp[i] != '\n')
		{
			ft_putcolor("red");
			ft_putstr("ERROR\n");
			free(tmp);
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_check_m(char **m)
{
	int i;

	i = 0;
	while (m[i])
	{
		if (ft_atoi(m[i]) < 1 || ft_atoi(m[i]) > 10000)
		{
			ft_putcolor("red");
			ft_putstr("ERROR\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_read_file(int fd)
{
	t_alcu	v;
	char	*tmp;

	tmp = ft_strnew(BUFF_SIZE);
	while ((v.ret = read(fd, v.buf, BUFF_SIZE)) && !ft_memchr(v.buf, '\n', 1))
	{
		v.buf[v.ret] = '\0';
		tmp = ft_strjoin(tmp, v.buf);
	}
	if (!ft_check(tmp))
		return (NULL);
	v.m = ft_strsplit(tmp, '\n');
	free(tmp);
	if (!ft_check_m(v.m))
		return (NULL);
	return (v.m);
}
