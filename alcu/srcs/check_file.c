/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:13:11 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/21 11:45:18 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	ft_check(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if ((!ft_isdigit(tmp[i]) && tmp[i] != '\n') || tmp[0] == '0')
		{
			ft_putcolor("red");
			ft_putstr("ERROR\n");
			exit(0);
		}
		i++;
	}
}

char	**ft_read_file(int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	**m;
	char	*tmp;

	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) && !ft_memchr(buf, '\n', 1))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (fd == 0)
			ft_check(tmp);
	}
	ft_check(tmp);
	m = ft_strsplit(tmp, '\n');
	return (m);
}
