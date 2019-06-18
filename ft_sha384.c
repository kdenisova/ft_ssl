/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha384.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:45:43 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/18 10:45:46 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sha224_init(t_fsha *fsh, char *arg, int len)
{
	fsh->hash[0] = 0xc1059ed8;
	fsh->hash[1] = 0x367cd507;
	fsh->hash[2] = 0x3070dd17;
	fsh->hash[3] = 0xf70e5939;
	fsh->hash[4] = 0xffc00b31;
	fsh->hash[5] = 0x68581511;
	fsh->hash[6] = 0x64f98fa7;
	fsh->hash[7] = 0xbefa4fa4;
	fsh->round = 64;
	fsh->hash_len = 7;
	if (len)
		fsh->len = len;
	else
		fsh->len = ft_strlen(arg);
	fsh->bitlen = fsh->len * 8;
}

void	sha384_init(t_fsha *fsh, char *arg, int len)
{
	fsh->hash[0] = 0xcbbb9d5dc1059ed8;
	fsh->hash[1] = 0x629a292a367cd507;
	fsh->hash[2] = 0x9159015a3070dd17;
	fsh->hash[3] = 0x152fecd8f70e5939;
	fsh->hash[4] = 0x67332667ffc00b31;
	fsh->hash[5] = 0x8eb44a8768581511;
	fsh->hash[6] = 0xdb0c2e0d64f98fa7;
	fsh->hash[7] = 0x47b5481dbefa4fa4;
	fsh->round = 80;
	fsh->hash_len = 6;
	if (len)
		fsh->len = len;
	else
		fsh->len = ft_strlen(arg);
	fsh->bitlen = fsh->len * 8;
}

void	ft_sha224(t_flg *flg, t_alp *al, char *arg, int len)
{
	t_fsha		fsh;
	unsigned	*w;

	sha224_init(&fsh, arg, len);
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

void	ft_sha384(t_flg *flg, t_alp *al, char *arg, int len)
{
	t_fsha			fsh;
	unsigned long	*w;

	sha384_init(&fsh, arg, len);
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
