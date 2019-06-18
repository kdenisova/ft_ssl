/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:11:40 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/30 13:11:43 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sha256_init(t_fsha *fsh, char *arg, int len)
{
	fsh->hash[0] = 0x6a09e667;
	fsh->hash[1] = 0xbb67ae85;
	fsh->hash[2] = 0x3c6ef372;
	fsh->hash[3] = 0xa54ff53a;
	fsh->hash[4] = 0x510e527f;
	fsh->hash[5] = 0x9b05688c;
	fsh->hash[6] = 0x1f83d9ab;
	fsh->hash[7] = 0x5be0cd19;
	fsh->round = 64;
	fsh->hash_len = 8;
	if (len)
		fsh->len = len;
	else
		fsh->len = ft_strlen(arg);
	fsh->bitlen = fsh->len * 8;
}

void	sha512_init(t_fsha *fsh, char *arg, int len)
{
	fsh->hash[0] = 0x6a09e667f3bcc908;
	fsh->hash[1] = 0xbb67ae8584caa73b;
	fsh->hash[2] = 0x3c6ef372fe94f82b;
	fsh->hash[3] = 0xa54ff53a5f1d36f1;
	fsh->hash[4] = 0x510e527fade682d1;
	fsh->hash[5] = 0x9b05688c2b3e6c1f;
	fsh->hash[6] = 0x1f83d9abfb41bd6b;
	fsh->hash[7] = 0x5be0cd19137e2179;
	fsh->round = 80;
	fsh->hash_len = 8;
	if (len)
		fsh->len = len;
	else
		fsh->len = ft_strlen(arg);
	fsh->bitlen = fsh->len * 8;
}

void	ft_sha256(t_flg *flg, t_alp *al, char *arg, int len)
{
	t_fsha		fsh;
	unsigned	*w;

	sha256_init(&fsh, arg, len);
	if (fsh.len >= BLOCK_SIZE - 8)
		arg = get_block_sha256(&fsh, al, arg);
	w = ft_memalloc(sizeof(unsigned int) * 64);
	ft_memset(w, 0, sizeof(w));
	if (fsh.len >= 0)
	{
		ft_memcpy(w, arg, fsh.len);
		((char *)w)[fsh.len] = 0x80;
	}
	((char *)w)[fsh.round - 4] = (fsh.bitlen & 0xFF000000) >> 24;
	((char *)w)[fsh.round - 3] = (fsh.bitlen & 0x00FF0000) >> 16;
	((char *)w)[fsh.round - 2] = (fsh.bitlen & 0x0000FF00) >> 8;
	((char *)w)[fsh.round - 1] = (fsh.bitlen & 0x000000FF);
	sha_stages(&fsh, al, w);
	free(w);
	put_sha(flg, &fsh, arg, put_hash_sha256);
}

void	ft_sha512(t_flg *flg, t_alp *al, char *arg, int len)
{
	t_fsha			fsh;
	unsigned long	*w;

	sha512_init(&fsh, arg, len);
	if (fsh.len >= SIZE_SHA - 16)
		arg = get_block_sha512(&fsh, al, arg);
	w = ft_memalloc(sizeof(unsigned long) * 80);
	ft_memset(w, 0, sizeof(w));
	if (fsh.len >= 0)
	{
		ft_memcpy(w, arg, fsh.len);
		((char *)w)[fsh.len] = 0x80;
	}
	sha512_stages(&fsh, al, w);
	free(w);
	put_sha(flg, &fsh, arg, put_hash_sha512);
}
