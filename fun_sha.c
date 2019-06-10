/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:11:51 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/30 13:11:53 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

const unsigned	g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

unsigned	rotr(unsigned x, unsigned n)
{
	return ((x >> n) | (x << (32 - n)));
}

unsigned	revers_data(unsigned b)
{
	//return ((b << 24) | (b << 16) | (b << 8) | b);
	return ((b >> 24) | ((b & 0xff0000) >> 8) |
		((b & 0xff00) << 8) | (b << 24));
}

void		sha_rounds(t_fsha *fsh, t_alp *al, unsigned *w)
{
	int			i;

	i = 0;
	while (i < fsh->round)
	{
		fsh->s[1] = rotr(al->e, 6) ^ rotr(al->e, 11) ^ rotr(al->e, 25);
		fsh->ch = (al->e & al->f) ^ (~al->e & al->g);
		fsh->tmp1 = al->h + fsh->s[1] + fsh->ch + g_k[i] + w[i];
		fsh->s[0] = rotr(al->a, 2) ^ rotr(al->a, 13) ^ rotr(al->a, 22);
		fsh->maj = (al->a & al->b) ^ (al->a & al->c) ^ (al->b & al->c);
		fsh->tmp2 = fsh->s[0] + fsh->maj;
		al->h = al->g;
		al->g = al->f;
		al->f = al->e;
		al->e = al->d + fsh->tmp1;
		al->d = al->c;
		al->c = al->b;
		al->b = al->a;
		al->a = fsh->tmp1 + fsh->tmp2;
		i++;
	}
}

void		sha_stages(t_fsha *fsh, t_alp *al, unsigned *w)
{
	sha_update(fsh, w);
	al->a = fsh->hash[0];
	al->b = fsh->hash[1];
	al->c = fsh->hash[2];
	al->d = fsh->hash[3];
	al->e = fsh->hash[4];
	al->f = fsh->hash[5];
	al->g = fsh->hash[6];
	al->h = fsh->hash[7];
	sha_rounds(fsh, al, w);
	fsh->hash[0] += al->a;
	fsh->hash[1] += al->b;
	fsh->hash[2] += al->c;
	fsh->hash[3] += al->d;
	fsh->hash[4] += al->e;
	fsh->hash[5] += al->f;
	fsh->hash[6] += al->g;
	fsh->hash[7] += al->h;
}
