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
	put_sha(flg, &fsh, arg);
}
