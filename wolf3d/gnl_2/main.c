/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtata <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:08:30 by vtata             #+#    #+#             */
/*   Updated: 2016/01/04 20:35:35 by vtata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		i;
	int		rt;

	i = 0;
	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	str = NULL;
	while ((rt = get_next_line(fd, &str)) > 0)
		ft_putendl(str);
	free(str);
	return (0);
}
