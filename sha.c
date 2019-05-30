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

void			sha_init(t_fsha *fsh, t_flg *flg)
{
	if (!ft_strcmp(flg->alg, "sha256"))
	{
		fsh->hash[0] = 0x6A09E667;
		fsh->hash[1] = 0xBB67AE85;
		fsh->hash[2] = 0x3C6EF372;
		fsh->hash[3] = 0xA54FF53A;
		fsh->hash[4] = 0x510E527F;
		fsh->hash[5] = 0x9B05688C;
		fsh->hash[6] = 0x1F83D9AB;
		fsh->hash[7] = 0x5BE0CD19;
		fsh->r = 64;
	}
	// else //for SHA512
	// {
	//     fsh->h[0] = 0x6a09e667f3bcc908;
	//     fsh->h[1] = 0xbb67ae8584caa73b;
	//     fsh->h[2] = 0x3c6ef372fe94f82b;
	//     fsh->h[3] = 0xa54ff53a5f1d36f1;
	//     fsh->h[4] = 0x510e527fade682d1;
	//     fsh->h[5] = 0x9b05688c2b3e6c1f;
	//     fsh->h[6] = 0x1f83d9abfb41bd6b;
	//     fsh->h[7] = 0x5be0cd19137e2179;
	//     fsh->r = 80;
	// }
}

unsigned	*sha_update(t_fsha *fsh, char *str, unsigned int *w)
{
	int i;
	int size;

	fsh->len = ft_strlen(str);
	fsh->bitlen = fsh->len * 8;
	size = 1 + ((fsh->bitlen + 16 + 64) / 512);
	ft_memcpy((char *)w, str, fsh->len);
	((char *)w)[fsh->len] = 0x80;
	i = 0;
	while (i < (size * 16) - 1)
	{
		w[i] = revers_data(w[i]);
		i++;
	}
	w[((size * 512 - 64) / 32) + 1] = fsh->bitlen;
	return (w);
}

unsigned		*sha_final(t_fsha *fsh, unsigned hash[])
{
	int			i;
	int			j;
	
	i = 0;
	j = 0;
	while (i < 8)
	{
		hash[j++] = (unsigned char) (fsh->hash[i] >> 24);
		hash[j++] = (unsigned char) (fsh->hash[i] >> 16);
		hash[j++] = (unsigned char) (fsh->hash[i] >> 8);
		hash[j++] = (unsigned char) fsh->hash[i];
		i++;
	}
	return (hash);
}

void    print_sha(t_fsha *fsh)
{
	int         i;

	i = 0;
	while (i < 8)
	{
		ft_printf("%x", fsh->hash[i]);
		i++;
	}
}

void	ft_sha(t_flg *flg, t_alp *al, char *arg)
{
	t_fsha          fsh;
	unsigned int	*w;
	int				i;

	sha_init(&fsh, flg);
	w = ft_memalloc(sizeof(unsigned int) * 64);
	sha_update(&fsh, arg, w);
	i = 16;
	while (i < fsh.r)
	{
		fsh.s[0] = rotr(w[i - 15], 7) ^ rotr(w[i - 15], 18) ^ (w[i - 15] >> 3);
		fsh.s[1] = rotr(w[i - 2], 17) ^ rotr(w[i - 2], 19) ^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + fsh.s[0] + w[i - 7] + fsh.s[1];
		i++;
	}
	sha_stages(&fsh, al, w);
	free(w);
	print_sha(&fsh);
	printf("\n");
}
