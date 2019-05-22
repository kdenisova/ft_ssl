/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:06:47 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/20 11:06:50 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	md5_init(t_fmd5 *fmd, char *str)
{
	fmd->hash[0] = 0x01234567;
	fmd->hash[1] = 0x89ABCDEF;
	fmd->hash[2] = 0xFEDCBA98;
	fmd->hash[3] = 0x76543210;
	fmd->hash[4] = 0;
	fmd->hash[5] = 0;
	fmd->hash[6] = 0;
	fmd->hash[7] = 0;
	fmd->bits[0] = 0;
	fmd->bits[1] = 0;
	fmd->len = ft_strlen(str);
	fmd->bitlen = fmd->len * 8;
}

unsigned char *transform_data(t_fmd5 *fmd, char *str)
{
	int		rem;
	int		size;
	int		i;
	unsigned char	*data;

	rem = fmd->len % 64;
	size = 0;
	if (rem < 56)
		size = fmd->len - rem + 64;
	else
		size = fmd->len - rem + 128;
	data = (unsigned char *)ft_strnew(size);
	data = (unsigned char *)ft_strncpy((char *)data, str, fmd->len);
	data[fmd->len] = 1;
	// fmd->len++;
	// while (fmd->len < size)
	// {
	// 	data[fmd->len] = 0;
	// 	fmd->len++;
	// }
	data = (unsigned char *)ft_strcat((char *)data, (char *)ft_memset(&data[fmd->len + 1], 0, size));
	i = 0;
	while (i < 8)
	{
		data[size - 8 + i] = (unsigned char)(fmd->bitlen >> i * 8);
		i++;
	}
	//printf("data = %s\nsize = %d\n", data, (int)ft_strlen((char *)data));
	return (data);
}

int		main(void)
{
	t_fmd5 fmd;
	char *str = "abc";
	unsigned *x;
	int i;
	//char *str1 = "bc";
	
	md5_init(&fmd, str);
	x = (unsigned *)ft_strnew(16);
	x = (unsigned *)transform_data(&fmd, str);
	stage_one(&fmd, x);
	i = 0;
	printf("md5 = ");
	while (i < 4)
	{
		printf("%s", ft_itoa_base(fmd.hash[i], 16));
		i++;
	}
	printf("\n");
	return (0);
}

// unsigned t[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	// 					0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	// 					0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	// 					0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	// 					0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	// 					0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	// 					0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	// 					0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	// 					0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	// 					0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	// 					0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	// 					0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	// 					0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	// 					0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	// 					0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	// 					0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
	//       k s  i		 k s   i		k s   i		   k s   i