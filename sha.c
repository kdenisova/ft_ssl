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

void		sha_init(t_fsha *fsh, t_flg *flg)
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
		fsh->round = 64;
	}
	else
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
	}
}

unsigned	*sha_update(t_fsha *fsh, char *str, unsigned int *w)
{
	int i;

	i = 0;
	fsh->len = ft_strlen(str);
	fsh->bitlen = fsh->len * 8;
	ft_memset(w, 0, sizeof(w));
	ft_memcpy(w, str, fsh->len);
	((char *)w)[fsh->len] = 0x80;
	((char *)w)[fsh->round - 4] = (fsh->bitlen & 0xFF000000) >> 24;
	((char *)w)[fsh->round - 3] = (fsh->bitlen & 0x00FF0000) >> 16;
	((char *)w)[fsh->round - 2] = (fsh->bitlen & 0x0000FF00) >> 8;
	((char *)w)[fsh->round - 1] = (fsh->bitlen & 0x000000FF);
	while (i < 16)
	{
		w[i] = revers_data(w[i]);
		i++;
	}
	return (w);
}

void		put_sha(t_flg *flg, t_fsha *fsh)
{
	int i;

	i = 0;
	if (!ft_strcmp(flg->alg, "sha256"))
	{
		while (i < 8)
		{
			ft_printf("%02x", fsh->hash[i]);
			i++;
		}
	}
	else
	{
		while (i < 8)
		{
			ft_printf("%lx", fsh->hash[i]);
			i++;
		}
	}
}

void		ft_sha256(t_fsha *fsh, t_alp *al, char *arg)
{
	unsigned		*w;
	int				i;

	w = ft_memalloc(sizeof(unsigned int) * 64);
	sha_update(fsh, arg, w);
	i = 16;
	while (i < fsh->round)
	{
		fsh->s[0] = rotr(w[i - 15], 7) ^ rotr(w[i - 15], 18) ^ (w[i - 15] >> 3);
		fsh->s[1] = rotr(w[i - 2], 17) ^ rotr(w[i - 2], 19) ^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + fsh->s[0] + w[i - 7] + fsh->s[1];
		i++;
	}
	sha_stages(fsh, al, w);
	free(w);
}

void		ft_sha(t_flg *flg, t_alp *al, char *arg)
{
	t_fsha			fsh;

	sha_init(&fsh, flg);
	if (!ft_strcmp(flg->alg, "sha256"))
		ft_sha256(&fsh, al, arg);
	else
		ft_sha512(&fsh, al, arg);
	if (flg->q == 0 && flg->r == 0)
	{
		ft_printf("SHA256 (\"%s\") = ", arg);
		put_sha(flg, &fsh);
	}
	else if (flg->r)
	{
		put_sha(flg, &fsh);
		ft_printf(" \"%s\"", arg);
	}
	else if (flg->q)
		put_sha(flg, &fsh);
	ft_printf("\n");
}
