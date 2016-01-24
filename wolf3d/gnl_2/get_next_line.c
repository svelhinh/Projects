/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 14:21:12 by vtata             #+#    #+#             */
/*   Updated: 2016/01/10 17:38:04 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check(char b_or_r[], int max)
{
	int i;
	int	size;

	i = 0;
	size = (max) ? max : BUFF_SIZE;
	while (i < size)
	{
		if (b_or_r[i] == '\0')
			return (2);
		if (b_or_r[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

static void	write_b_r_to_line(char **line, char b_or_r[], int size, int v)
{
	int		i;
	char	*tmp;
	char	*line_tmp;

	i = 0;
	line_tmp = ft_strdup((*line));
	free(*line);
	if (v == 1)
	{
		while (b_or_r[i] != '\n')
			++i;
		size = i;
		i = 0;
	}
	tmp = ft_strnew(size + 1);
	while (i < size)
	{
		tmp[i] = b_or_r[i];
		++i;
	}
	tmp[i] = '\0';
	(*line) = ft_strjoin(line_tmp, tmp);
	free(tmp);
	free(line_tmp);
}

static char	*build_rest(char buf[], int max)
{
	char		*rest;
	int			i;
	int			start;

	if (!(rest = (char*)malloc(sizeof(*rest) * (max + 1))))
		return (NULL);
	i = 0;
	while (buf[i] != '\n')
		++i;
	start = i + 1;
	i = 0;
	rest[0] = '\0';
	if (buf[start] != '\0')
	{
		while (start < max && buf[start] != '\0')
			rest[i++] = buf[start++];
		rest[i] = '\0';
	}
	return (rest);
}

static void	line_saver(char **line, char *rest, int ret)
{
	if (((*line) = (char*)malloc(1)))
		(*line)[0] = '\0';
	if ((rest && rest[0] != '\0') && ret == BUFF_SIZE && (check(rest, 0) != 1))
		write_b_r_to_line(line, rest, BUFF_SIZE, 0);
	if ((rest && rest[0] != '\0') && ret == BUFF_SIZE && (check(rest, 0) != 1))
		rest[0] = '\0';
}

int			get_next_line(int const fd, char **line)
{
	static char		*rest[256];
	char			buf[BUFF_SIZE];
	static int		ret = 1;

	if (fd < 0 || !line)
		return (-1);
	line_saver(line, rest[fd], ret);
	while ((!rest[fd] || rest[fd][0] == '\0') \
		&& (ret = read(fd, buf, BUFF_SIZE)) > 0 && check(buf, 0) == 0)
		write_b_r_to_line(line, buf, ret, 0);
	if (ret == 0 && (!rest[fd] || rest[fd][0] == '\0') && (*line)[0] == '\0')
		return (0);
	if (ret == -1)
		return (-1);
	if (rest[fd] && rest[fd][0] != '\0')
	{
		write_b_r_to_line(line, rest[fd], ret, (check(rest[fd], 0)));
		((check(rest[fd], 0)) == 2) ? rest[fd][0] = '\0' : 0;
		((check(rest[fd], 0)) == 1) ? rest[fd] = build_rest(rest[fd], ret) : 0;
		return (1);
	}
	write_b_r_to_line(line, buf, ret, (check(buf, ret)));
	((check(buf, ret)) == 1) ? rest[fd] = build_rest(buf, ret) : 0;
	return (1);
}
