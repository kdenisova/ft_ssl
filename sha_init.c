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
