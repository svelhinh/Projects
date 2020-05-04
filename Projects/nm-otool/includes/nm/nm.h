/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:11:04 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 13:34:44 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include "utils.h"

typedef struct		s_sect
{
	char			*name;
	uint32_t		idx;
	struct s_sect	*next;
}					t_sect;

void				merge_sort(t_sym **head_ref);

t_sym				**get_syms_64(int nsyms, int stroff, char *ptr,
	t_nlist_64 *array);
char				get_sym_sect_64(t_sym *sym, t_sect **sects);
void				get_sects_64(t_sect **sect, uint32_t *id, t_load_com *lc);
void				handle_64(char *ptr);

t_sym				**get_syms_32(int nsyms, int stroff, char *ptr,
	t_nlist *array);
char				get_sym_sect_32(t_sym *sym, t_sect **sects);
void				get_sects_32(t_sect **sect, uint32_t *id, t_load_com *lc);
void				handle_32(char *ptr);

void				handle_fat(char *filename, char *ptr);

#endif
