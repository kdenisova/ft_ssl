/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:33:20 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/03 13:33:22 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

const unsigned long	g_kk[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

unsigned long	*sha512_update(t_fsha *fsh, unsigned long *w)
{
	int i;

	i = 0;
	while (i < 15)
	{
		w[i] = revers_bits_64(w[i]);
		i++;
	}
	if (fsh->len < SIZE_SHA - 16)
		sha_padding(fsh, w);
	else
		w[i] = revers_bits_64(w[i]);
	i++;
	while (i < fsh->round)
	{
		fsh->s[0] = r_64(w[i - 15], 1) ^ r_64(w[i - 15], 8) ^ (w[i - 15] >> 7);
		fsh->s[1] = r_64(w[i - 2], 19) ^ r_64(w[i - 2], 61) ^ (w[i - 2] >> 6);
		w[i] = w[i - 16] + fsh->s[0] + w[i - 7] + fsh->s[1];
		i++;
	}
	return (w);
}

unsigned long	*sha_padding(t_fsha *fsh, unsigned long *w)
{
	((char *)w)[SIZE_SHA - 1] = (fsh->bitlen & 0xFF00000000000000) >> 56;
	((char *)w)[SIZE_SHA - 2] = (fsh->bitlen & 0x00FF000000000000) >> 48;
	((char *)w)[SIZE_SHA - 3] = (fsh->bitlen & 0x0000FF0000000000) >> 40;
	((char *)w)[SIZE_SHA - 4] = (fsh->bitlen & 0x000000FF00000000) >> 32;
	((char *)w)[SIZE_SHA - 5] = (fsh->bitlen & 0x00000000FF000000) >> 24;
	((char *)w)[SIZE_SHA - 6] = (fsh->bitlen & 0x0000000000FF0000) >> 16;
	((char *)w)[SIZE_SHA - 7] = (fsh->bitlen & 0x000000000000FF00) >> 8;
	((char *)w)[SIZE_SHA - 8] = (fsh->bitlen & 0x00000000000000FF);
	((char *)w)[SIZE_SHA - 9] = (fsh->bitlen >> 64 & 0xFF00000000000000) >> 56;
	((char *)w)[SIZE_SHA - 10] = (fsh->bitlen >> 64 & 0x00FF000000000000) >> 48;
	((char *)w)[SIZE_SHA - 11] = (fsh->bitlen >> 64 & 0x0000FF0000000000) >> 40;
	((char *)w)[SIZE_SHA - 12] = (fsh->bitlen >> 64 & 0x000000FF00000000) >> 32;
	((char *)w)[SIZE_SHA - 13] = (fsh->bitlen >> 64 & 0x00000000FF000000) >> 24;
	((char *)w)[SIZE_SHA - 14] = (fsh->bitlen >> 64 & 0x0000000000FF0000) >> 16;
	((char *)w)[SIZE_SHA - 15] = (fsh->bitlen >> 64 & 0x000000000000FF00) >> 8;
	((char *)w)[SIZE_SHA - 16] = (fsh->bitlen >> 64 & 0x00000000000000FF);
	return (w);
}

void			sha512_rounds(t_fsha *fsh, t_alp *al, unsigned long *w)
{
	int			i;

	i = 0;
	while (i < fsh->round)
	{
		fsh->s[1] = r_64(al->e, 14) ^ r_64(al->e, 18) ^ r_64(al->e, 41);
		fsh->ch = (al->e & al->f) ^ ((~al->e) & al->g);
		fsh->tmp1 = al->h + fsh->s[1] + fsh->ch + g_kk[i] + w[i];
		fsh->s[0] = r_64(al->a, 28) ^ r_64(al->a, 34) ^ r_64(al->a, 39);
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

void			sha512_stages(t_fsha *fsh, t_alp *al, unsigned long *w)
{
	sha512_update(fsh, w);
	al->a = fsh->hash[0];
	al->b = fsh->hash[1];
	al->c = fsh->hash[2];
	al->d = fsh->hash[3];
	al->e = fsh->hash[4];
	al->f = fsh->hash[5];
	al->g = fsh->hash[6];
	al->h = fsh->hash[7];
	sha512_rounds(fsh, al, w);
	fsh->hash[0] += al->a;
	fsh->hash[1] += al->b;
	fsh->hash[2] += al->c;
	fsh->hash[3] += al->d;
	fsh->hash[4] += al->e;
	fsh->hash[5] += al->f;
	fsh->hash[6] += al->g;
	fsh->hash[7] += al->h;
}

char			*get_block_sha512(t_fsha *fsh, t_alp *al, char *arg)
{
	unsigned long	*w;

	while (fsh->len >= SIZE_SHA - 16)
	{
		w = ft_memalloc(sizeof(unsigned long) * 80);
		if (fsh->len < SIZE_SHA)
		{
			ft_memset(w, 0, sizeof(w));
			ft_memcpy(w, arg, fsh->len);
			((char *)w)[fsh->len] = 0x80;
			sha512_stages(fsh, al, w);
			arg = arg + fsh->len;
			fsh->len = -1;
		}
		else
		{
			ft_memcpy(w, arg, SIZE_SHA);
			sha512_stages(fsh, al, w);
			arg = arg + SIZE_SHA;
			fsh->len = fsh->len - SIZE_SHA;
		}
		free(w);
	}
	return (arg);
}
