/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 18:32:33 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 14:04:17 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	available_section(char *section_name)
{
	if (!ft_strcmp(section_name, "__text"))
		return ('t');
	if (!ft_strcmp(section_name, "__data"))
		return ('d');
	if (!ft_strcmp(section_name, "__bss"))
		return ('b');
	return ('s');
}

int		reverse_int(int value)
{
	unsigned char msb;
	unsigned char b2;
	unsigned char b3;
	unsigned char lsb;

	msb = value;
	b2 = value >> 8;
	b3 = value >> 16;
	lsb = value >> 24;
	return (((int)msb << 24) + ((int)b2 << 16) + ((int)b3 << 8) + lsb);
}

void	print_arch(int cpu_type, int nfat_arch, char *filename)
{
	char	*arch;

	if (nfat_arch != 1)
	{
		ft_putchar('\n');
		ft_putstr(filename);
		ft_putstr(" (");
		if (cpu_type == CPU_TYPE_X86_64)
			arch = ft_strdup("for architecture ppc");
		else if (cpu_type == CPU_TYPE_POWERPC64)
			arch = ft_strdup("for architecture ppc64");
		else if (cpu_type == CPU_TYPE_SPARC)
			arch = ft_strdup("for architecture sparc");
		else if (cpu_type == CPU_TYPE_X86)
			arch = ft_strdup("for architecture i386");
		else if (cpu_type == CPU_TYPE_X86_64)
			arch = ft_strdup("for architecture x86_64");
		else
			arch = ft_strdup("Unrecognized architecture");
		ft_putstr(arch);
		ft_putendl("):");
	}
}

int		arch_match(int nfat_arch, t_fat_arch *f_arch)
{
	int	i;
	int	offset;

	i = 0;
	offset = 0;
	while (i < nfat_arch)
	{
		if (reverse_int(f_arch->cputype) == CPU)
		{
			offset = reverse_int(f_arch->offset);
			break ;
		}
		f_arch = (void *)f_arch + sizeof(*f_arch);
		i++;
	}
	return (offset);
}
