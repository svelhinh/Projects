/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:23:08 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 18:39:52 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	set_registers(unsigned int (*reg)[8], unsigned int *w,
	unsigned int s[2])
{
	unsigned int	i;
	unsigned int	ch;
	unsigned int	tmp1;
	unsigned int	tmp2;
	unsigned int	maj;

	i = -1;
	while (++i < 64)
	{
		s[1] = RROT((*reg)[4], 6) ^ RROT((*reg)[4], 11) ^ RROT((*reg)[4], 25);
		ch = ((*reg)[4] & (*reg)[5]) ^ (~(*reg)[4] & (*reg)[6]);
		tmp1 = (*reg)[7] + s[1] + ch + g_k[i] + w[i];
		s[0] = RROT((*reg)[0], 2) ^ RROT((*reg)[0], 13) ^ RROT((*reg)[0], 22);
		maj = ((*reg)[0] & (*reg)[1]) ^ ((*reg)[0] & (*reg)[2]) ^ ((*reg)[1] &
			(*reg)[2]);
		tmp2 = s[0] + maj;
		(*reg)[7] = (*reg)[6];
		(*reg)[6] = (*reg)[5];
		(*reg)[5] = (*reg)[4];
		(*reg)[4] = (*reg)[3] + tmp1;
		(*reg)[3] = (*reg)[2];
		(*reg)[2] = (*reg)[1];
		(*reg)[1] = (*reg)[0];
		(*reg)[0] = tmp1 + tmp2;
	}
}

static void	split_chunk(unsigned char *new_msg, unsigned int offset,
	unsigned int (*w)[64], unsigned int (*s)[2])
{
	unsigned int	i;
	unsigned int	*chunk;

	chunk = (unsigned int *)(new_msg + offset);
	i = -1;
	while (++i < 16)
		(*w)[i] = ft_swap_32_endian(chunk[i]);
	i = 15;
	while (++i < 64)
	{
		(*s)[0] = RROT((*w)[i - 15], 7) ^ RROT((*w)[i - 15], 18) ^
			((*w)[i - 15] >> 3);
		(*s)[1] = RROT((*w)[i - 2], 17) ^ RROT((*w)[i - 2], 19) ^
			((*w)[i - 2] >> 10);
		(*w)[i] = (*w)[i - 16] + (*s)[0] + (*w)[i - 7] + (*s)[1];
	}
}

void		hash_new_msg_sha256(unsigned char *new_msg, unsigned int len,
	unsigned int (*h1)[8])
{
	unsigned int	i;
	unsigned int	offset;
	unsigned int	reg[8];
	unsigned int	s[2];
	unsigned int	w[64];

	offset = 0;
	while (offset < len)
	{
		split_chunk(new_msg, offset, &w, &s);
		i = -1;
		while (++i < 8)
			reg[i] = (*h1)[i];
		set_registers(&reg, w, s);
		i = -1;
		while (++i < 8)
			(*h1)[i] += reg[i];
		offset += 64;
	}
	free(new_msg);
	free(g_k);
}
