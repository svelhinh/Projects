/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:00:06 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 15:04:29 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	print_lines(t_sym *cur_sym, t_sect **first_sect)
{
	merge_sort(&cur_sym);
	while (cur_sym)
	{
		if ((cur_sym->type_flag & N_TYPE) == N_SECT)
		{
			cur_sym->type = get_sym_sect_64(cur_sym, first_sect);
			ft_putstr(cur_sym->addr);
		}
		else
			ft_putstr("                ");
		if ((cur_sym->type_flag & N_TYPE) == N_UNDF)
			cur_sym->type = 'u';
		if ((cur_sym->type_flag & N_TYPE) == N_ABS)
			cur_sym->type = 'a';
		if ((cur_sym->type_flag & N_TYPE) == N_INDR)
			cur_sym->type = 'i';
		if (cur_sym->type_flag & N_EXT)
			cur_sym->type = ft_toupper(cur_sym->type);
		ft_putchar(' ');
		ft_putchar(cur_sym->type);
		ft_putchar(' ');
		ft_putendl(cur_sym->name);
		cur_sym = cur_sym->next;
	}
}

static void	get_syms(char *ptr, t_sect **first_sect, t_mach_header_64 *header)
{
	uint32_t		i;
	t_symtab_com	*sym;
	t_nlist_64		*array;
	t_load_com		*lc;
	t_sym			**first_sym;

	first_sym = NULL;
	lc = (void *)ptr + sizeof(*header);
	i = 0;
	sym = NULL;
	header = (t_mach_header_64 *)ptr;
	while (i++ < header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (t_symtab_com *)lc;
			array = (void *)ptr + sym->symoff;
			first_sym = get_syms_64(sym->nsyms, sym->stroff, ptr, array);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
	}
	print_lines(*first_sym, first_sect);
}

/*
**	tmp[0] -> i
**	tmp[1] -> id
*/

void		handle_64(char *ptr)
{
	uint32_t			tmp[2];
	t_mach_header_64	*header;
	t_load_com			*lc;
	t_sect				*current_sect;
	t_sect				**first_sect;

	first_sect = (t_sect **)malloc(sizeof(t_sect *));
	current_sect = (t_sect *)malloc(sizeof(t_sect));
	*first_sect = current_sect;
	header = (t_mach_header_64 *)ptr;
	lc = (void *)ptr + sizeof(*header);
	tmp[0] = 0;
	tmp[1] = 1;
	while (tmp[0]++ < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			get_sects_64(&current_sect, &tmp[1], lc);
		lc = (void *)lc + lc->cmdsize;
	}
	get_syms(ptr, first_sect, header);
}
