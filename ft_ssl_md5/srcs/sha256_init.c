/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:24:46 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 19:07:59 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	init_k_3(void)
{
	g_k[46] = 0xf40e3585;
	g_k[47] = 0x106aa070;
	g_k[48] = 0x19a4c116;
	g_k[49] = 0x1e376c08;
	g_k[50] = 0x2748774c;
	g_k[51] = 0x34b0bcb5;
	g_k[52] = 0x391c0cb3;
	g_k[53] = 0x4ed8aa4a;
	g_k[54] = 0x5b9cca4f;
	g_k[55] = 0x682e6ff3;
	g_k[56] = 0x748f82ee;
	g_k[57] = 0x78a5636f;
	g_k[58] = 0x84c87814;
	g_k[59] = 0x8cc70208;
	g_k[60] = 0x90befffa;
	g_k[61] = 0xa4506ceb;
	g_k[62] = 0xbef9a3f7;
	g_k[63] = 0xc67178f2;
}

static void	init_k_2(void)
{
	g_k[22] = 0x5cb0a9dc;
	g_k[23] = 0x76f988da;
	g_k[24] = 0x983e5152;
	g_k[25] = 0xa831c66d;
	g_k[26] = 0xb00327c8;
	g_k[27] = 0xbf597fc7;
	g_k[28] = 0xc6e00bf3;
	g_k[29] = 0xd5a79147;
	g_k[30] = 0x06ca6351;
	g_k[31] = 0x14292967;
	g_k[32] = 0x27b70a85;
	g_k[33] = 0x2e1b2138;
	g_k[34] = 0x4d2c6dfc;
	g_k[35] = 0x53380d13;
	g_k[36] = 0x650a7354;
	g_k[37] = 0x766a0abb;
	g_k[38] = 0x81c2c92e;
	g_k[39] = 0x92722c85;
	g_k[40] = 0xa2bfe8a1;
	g_k[41] = 0xa81a664b;
	g_k[42] = 0xc24b8b70;
	g_k[43] = 0xc76c51a3;
	g_k[44] = 0xd192e819;
	g_k[45] = 0xd6990624;
	init_k_3();
}

/** Les 32 premiers bits de la partie décimale des racines carrés des 64 premiers nombres premiers **/
static void	init_k(void)
{
	g_k = ft_memalloc(64);
	ft_test_malloc(g_k);
	g_k[0] = 0x428a2f98;
	g_k[1] = 0x71374491;
	g_k[2] = 0xb5c0fbcf;
	g_k[3] = 0xe9b5dba5;
	g_k[4] = 0x3956c25b;
	g_k[5] = 0x59f111f1;
	g_k[6] = 0x923f82a4;
	g_k[7] = 0xab1c5ed5;
	g_k[8] = 0xd807aa98;
	g_k[9] = 0x12835b01;
	g_k[10] = 0x243185be;
	g_k[11] = 0x550c7dc3;
	g_k[12] = 0x72be5d74;
	g_k[13] = 0x80deb1fe;
	g_k[14] = 0x9bdc06a7;
	g_k[15] = 0xc19bf174;
	g_k[16] = 0xe49b69c1;
	g_k[17] = 0xefbe4786;
	g_k[18] = 0x0fc19dc6;
	g_k[19] = 0x240ca1cc;
	g_k[20] = 0x2de92c6f;
	g_k[21] = 0x4a7484aa;
	init_k_2();
}

void		init_sha256(unsigned int (*h1)[8])
{
	(*h1)[0] = 0x6a09e667;
	(*h1)[1] = 0xbb67ae85;
	(*h1)[2] = 0x3c6ef372;
	(*h1)[3] = 0xa54ff53a;
	(*h1)[4] = 0x510e527f;
	(*h1)[5] = 0x9b05688c;
	(*h1)[6] = 0x1f83d9ab;
	(*h1)[7] = 0x5be0cd19;
	init_k();
}
