/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat_otool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:09:13 by stoussay          #+#    #+#             */
/*   Updated: 2017/08/09 13:52:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void	choose_arch(char *ptr)
{
	unsigned int magic_number;

	magic_number = *(unsigned int *)ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		handle_64_otool(ptr);
	else if (magic_number == MH_MAGIC)
		handle_32_otool(ptr);
}

void		handle_fat_otool(char *ptr)
{
	int				nfat_arch;
	int				i;
	t_fat_header	*header;
	t_fat_arch		*f_arch;
	int				arch_offset;

	header = (t_fat_header *)ptr;
	nfat_arch = reverse_int(header->nfat_arch);
	f_arch = (void *)ptr + sizeof(*header);
	i = 0;
	arch_offset = arch_match(nfat_arch, f_arch);
	if (arch_offset)
		choose_arch((void *)ptr + arch_offset);
	else
	{
		while (i < nfat_arch)
		{
			choose_arch((void *)ptr + reverse_int(f_arch->offset));
			f_arch = (void *)f_arch + sizeof(*f_arch);
			i++;
		}
	}
}
