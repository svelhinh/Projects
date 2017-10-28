/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:36:14 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 15:12:03 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"
#include <stdio.h>

void		otool(char *ptr, char *filename)
{
	unsigned int	magic_number;

	magic_number = *(int *)ptr;
	ft_putstr(filename);
	ft_putendl(":");
	ft_putendl("Contents of (__TEXT,__text) section");
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		handle_64_otool(ptr);
	else if (magic_number == MH_MAGIC)
		handle_32_otool(ptr);
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		handle_fat_otool(ptr);
}

int			do_otool(char *filename, int fd)
{
	char	*ptr;
	t_stat	buf;

	if ((fstat(fd, &buf)) < 0)
	{
		ft_putendl("fstat failed");
		return (-1);
	}
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
		== MAP_FAILED)
	{
		ft_putendl("mmap failed");
		return (-1);
	}
	otool(ptr, filename);
	if (munmap(ptr, buf.st_size) < 0)
	{
		ft_putendl("munmap failed");
		return (-1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int nbargs;
	int fd;

	if (ac == 1)
	{
		ft_putendl("Please give me at least one arg");
		return (EXIT_FAILURE);
	}
	nbargs = 1;
	while (nbargs < ac)
	{
		if ((fd = open(av[nbargs], O_RDONLY)) < 0)
		{
			ft_putendl(ft_strjoin("Failed to open file : ", av[nbargs]));
			return (EXIT_FAILURE);
		}
		if (do_otool(av[nbargs], fd) < 0)
			return (EXIT_FAILURE);
		if (nbargs++ && close(fd) < 0)
		{
			ft_putendl(ft_strjoin("Failed to close file : ", av[nbargs]));
			return (EXIT_FAILURE);
		}
	}
	return (0);
}
