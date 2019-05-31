/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:25:53 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/23 14:25:55 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			md5_init(t_fmd5 *fmd, char *str)
{
	fmd->hash[0] = 0x67452301;
	fmd->hash[1] = 0xEFCDAB89;
	fmd->hash[2] = 0x98BADCFE;
	fmd->hash[3] = 0x10325476;
	fmd->hash[4] = 0;
	fmd->hash[5] = 0;
	fmd->hash[6] = 0;
	fmd->hash[7] = 0;
	fmd->len = ft_strlen(str);
	fmd->bitlen = fmd->len * 8;
}

unsigned	*md5_update(t_fmd5 *fmd, char *str, unsigned *x)
{
	int				rem;
	int				size;
	int				i;

	rem = fmd->len % 64;
	size = 0;
	if (rem < 56)
		size = fmd->len - rem + 64;
	else
		size = fmd->len - rem + 128;
	//size = fmd->len + 1;
	ft_memcpy((char *)x, str, fmd->len);
	((char *)x)[fmd->len] = 0x80;
	i = 0;
	printf("\n");
	while (i < 16)
	{
		printf("%u", x[i]);
		i++;
	}
	printf("\n");
	//ft_strcat((char *)x, ft_memset(&x[fmd->len + 1], 0, size));
	// i = 0;
	// while (i < 8)
	// {
	// 	x[size - 8 + i] = fmd->bitlen >> i * 8;
	// 	i++;
	// }
	// i = 0;
	// printf("\n");
	// while (i < 16)
	// {
	// 	printf("%u", x[i]);
	// 	i++;
	// }
	// printf("\n");
	// printf("\n%s\n", (char *)x);
	return (x);
}

unsigned		*md5_final(t_fmd5 *fmd)
{
	unsigned	*hash;
	int			i;
	int			j;

	i = 0;
	j = 0;
	hash = ft_memalloc(sizeof(unsigned int) * 64);
	while (i < 16)
	{
		hash[i] = (unsigned char)((fmd->hash[j]) & 0xff);
		hash[i + 1] = (unsigned char)((fmd->hash[j] >> 8) & 0xff);
		hash[i + 2] = (unsigned char)((fmd->hash[j] >> 16) & 0xff);
		hash[i + 3] = (unsigned char)((fmd->hash[j] >> 24) & 0xff);
		i = i + 4;
		j++;
	}
	return (hash);
}

void			put_hash(unsigned hash[], int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%02x", hash[i]);
		i++;
	}
}

void	ft_md5(t_fmd5 *fmd, t_flg *flg, t_alp *al, char *arg)
{
	unsigned *x;
	unsigned w[16];
	int i;
	int j;

	md5_init(fmd, arg);
	x = ft_memalloc(sizeof(unsigned int) * 64);
	md5_update(fmd, arg, x);
	i = 0;
	j = 0;
	while (i < 16)
	{
		w[i] = (x[j]) + (x[j + 1] << 8) + (x[j + 2] << 16) + (x[j + 3] << 24);
		printf("%u", w[i]);
		j = j + 4;
		i++;
	}

	// for (i=0,j=0; i < 16; ++i, j += 4) 
    //   m[i] = (data[j]) + (data[j+1] << 8) + (data[j+2] << 16) + (data[j+3] << 24); 
	//x[15] = 0;
	stage_one(fmd, al, w);
	if (flg->q == 0 && flg->r == 0)
	{
		ft_printf("MD5 (\"%s\") = ", arg);
		// md5_final(fmd);
		// printf("%x%x%x%x\n", fmd->hash[3], fmd->hash[2], fmd->hash[1], fmd->hash[0]);
		put_hash(md5_final(fmd), 16);
	}
	else if (flg->r)
	{
		put_hash(md5_final(fmd), 16);
		//printf(" \"%s\"", argv[flg.i]);
		ft_printf(" \"%s\" ", arg);
	}
	else if(flg->q)
		put_hash(md5_final(fmd), 16);
	free(x);
	printf("\n");
}
