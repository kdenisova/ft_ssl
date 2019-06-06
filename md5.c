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
	ft_memset(x, 0, sizeof(x));
	ft_memcpy(x, str, fmd->len);
	((char *)x)[fmd->len] = 0x80;
	((char *)x)[BLOCK_SIZE - 5] = (fmd->bitlen & 0xFF000000) >> 24;
	((char *)x)[BLOCK_SIZE - 6] = (fmd->bitlen & 0x00FF0000) >> 16;
	((char *)x)[BLOCK_SIZE - 7] = (fmd->bitlen & 0x0000FF00) >> 8;
	((char *)x)[BLOCK_SIZE - 8] = (fmd->bitlen & 0x000000FF);
	return (x);
}

unsigned		*md5_final(t_fmd5 *fmd)
{
	unsigned	*hash;
	int			i;
	int			j;

	i = 0;
	j = 0;
	hash = ft_memalloc(sizeof(unsigned int) * 16);
	while (i < 16)
	{
		hash[i] = (unsigned char)((fmd->hash[j]) & 0xFF);
		hash[i + 1] = (unsigned char)((fmd->hash[j] >> 8) & 0xFF);
		hash[i + 2] = (unsigned char)((fmd->hash[j] >> 16) & 0xFF);
		hash[i + 3] = (unsigned char)((fmd->hash[j] >> 24) & 0xFF);
		i = i + 4;
		j++;
	}
	return (hash);
}

void			put_md5(unsigned *hash)
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", hash[i]);
		i++;
	}
}

void			ft_md5(t_fmd5 *fmd, t_flg *flg, t_alp *al, char *arg)
{
	unsigned *x;

	md5_init(fmd, arg);
	printf("str = %s\n", arg);
	// printf("\nlen = %d\n", fmd->len);
	// while (fmd->len >= BLOCK_SIZE - 8)
	// {
	// 	printf("\nwhile\n");
	// 	x = ft_memalloc(sizeof(unsigned int) * 64);
	// 	if (fmd->len < BLOCK_SIZE)
	// 	{
	// 		md5_update(fmd, arg, x);
	// 		stage_one(fmd, al, x);
	// 		arg = arg + fmd->len;
	// 		fmd->len = -1;
	// 	}
	// 	else
	// 	{
	// 		stage_one(fmd, al, (unsigned int *)arg);
	// 		arg = arg + BLOCK_SIZE;
	// 		fmd->len = fmd->len - BLOCK_SIZE;
	// 	}
	// 	free(x);
	// 	put_md5(md5_final(fmd));
	// }
	// printf("\nend while\n");
	// if (fmd->len >= 0)
	// {
	// 	x = ft_memalloc(sizeof(unsigned int) * 64);
	// 	md5_update(fmd, arg, x);
	// 	stage_one(fmd, al, x);
	// 	free(x);
	// }
	x = ft_memalloc(sizeof(unsigned int) * 64);
	md5_update(fmd, arg, x);
	stage_one(fmd, al, x);
	free(x);
	if (flg->q == 0 && flg->r == 0)
	{
		ft_printf("MD5 (\"%s\") = ", arg);
		put_md5(md5_final(fmd));
	}
	else if (flg->r)
	{
		put_md5(md5_final(fmd));
		ft_printf(" \"%s\"", arg);
	}
	else if (flg->q)
		put_md5(md5_final(fmd));
	printf("\n");
}


// while ( len >= MD5_INPUT_BLOCK_SIZE )
//   {
//     // Special handling for blocks between 56 and 64 bytes
//     // (not enough room for the 8 bytes of length, but also
//     // not enough to fill up a block)
//     if ( len < MD5_BLOCK_SIZE )
//     {
//       memset( padded_block, 0, sizeof( padded_block ) );
//       memcpy( padded_block, input, len );
//       padded_block[ len ] = 0x80;
//       md5_block_operate( padded_block, hash );
//       input += len;
//       len = -1;
// 	  } else {
//       md5_block_operate( input, hash );
//       input += MD5_BLOCK_SIZE;
//       len -= MD5_BLOCK_SIZE;
//     }
// }
//   // There’s always at least one padded block at the end, which includes
//   // the length of the message
//   memset( padded_block, 0, sizeof( padded_block ) );
//   if ( len >= 0 )
//   {
//     memcpy( padded_block, input, len );
//     padded_block[ len ] = 0x80;
// }
