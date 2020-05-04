/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 17:32:56 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 17:41:19 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	swap_registers(unsigned int (*reg)[6], unsigned int *w,
	unsigned int r[64], int i)
{
	unsigned int	tmp;

	tmp = (*reg)[3];
	(*reg)[3] = (*reg)[2];
	(*reg)[2] = (*reg)[1];
	(*reg)[1] += LROT(((*reg)[0] + (*reg)[4] + g_k[i] + w[(*reg)[5]]), r[i]);
	(*reg)[0] = tmp;
}

static void	set_registers(unsigned int (*reg)[6], unsigned int *w,
	unsigned int r[64], int i)
{
	while (++i < 64)
	{
		if (i < 16)
		{
			(*reg)[4] = ((*reg)[1] & (*reg)[2]) | ((~(*reg)[1]) & (*reg)[3]);
			(*reg)[5] = i;
		}
		else if (i < 32)
		{
			(*reg)[4] = ((*reg)[3] & (*reg)[1]) | ((~(*reg)[3]) & (*reg)[2]);
			(*reg)[5] = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			(*reg)[4] = (*reg)[1] ^ (*reg)[2] ^ (*reg)[3];
			(*reg)[5] = (3 * i + 5) % 16;
		}
		else
		{
			(*reg)[4] = (*reg)[2] ^ ((*reg)[1] | (~(*reg)[3]));
			(*reg)[5] = (7 * i) % 16;
		}
		swap_registers(reg, w, r, i);
	}
}

void		hash_new_msg_md5(unsigned char *new_msg, unsigned int len,
	unsigned int (*h)[4], unsigned int r[64])
{
	unsigned int	offset;
	unsigned int	reg[6];
	unsigned int	*w;
	int				i;

	offset = 0;
	while (offset < len)
	{
		w = (unsigned int *)(new_msg + offset);	// Permet d'avancer au bloc suivant
		reg[0] = (*h)[0];
		reg[1] = (*h)[1];
		reg[2] = (*h)[2];
		reg[3] = (*h)[3];
		i = -1;
		set_registers(&reg, w, r, i);
		(*h)[0] += reg[0];
		(*h)[1] += reg[1];
		(*h)[2] += reg[2];
		(*h)[3] += reg[3];
		offset += 64;	// On découpe le message en blocs de 512 bits soit 64 caractères
	}
	free(new_msg);
	free(g_k);
}
