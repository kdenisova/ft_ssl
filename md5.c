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

unsigned char	*md5_update(t_fmd5 *fmd, char *str)
{
	int				rem;
	int				size;
	int				i;
	unsigned char	*data;

	rem = fmd->len % 64;
	size = 0;
	if (rem < 56)
		size = fmd->len - rem + 64;
	else
		size = fmd->len - rem + 128;
	data = (unsigned char *)ft_strnew(size);
	data = (unsigned char *)ft_strncpy((char *)data, str, fmd->len);
	data[fmd->len] = 0x80;
	data = (unsigned char *)ft_strcat((char *)data,
		(char *)ft_memset(&data[fmd->len + 1], 0, size));
	i = 0;
	while (i < 8)
	{
		data[size - 8 + i] = (unsigned char)(fmd->bitlen >> i * 8);
		i++;
	}
	return (data);
}

unsigned		*md5_final(t_fmd5 *fmd)
{
	unsigned	*hash;
	int			i;
	int			j;

	i = 0;
	j = 0;
	hash = (unsigned *)ft_strnew(16);
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

void			print_md5(unsigned hash[])
{
	int i;

	i = 0;
	while (i < 16)
	{
		printf("%02x", hash[i]);
		i++;
	}
}
