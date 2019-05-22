/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_stages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:59:39 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/22 10:59:42 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	stage_one(t_fmd5 *fmd, unsigned *x)
{
	unsigned a;
	unsigned b;
	unsigned c;
	unsigned d;

	a = fmd->hash[0];
	b = fmd->hash[1];
	c = fmd->hash[2];
	d = fmd->hash[3];
	a = b + ((a + fun_f(b, c, d) + x[0] + 0xd76aa478) << 7);
	d = a + ((d + fun_f(a, b, c) + x[1] + 0xe8c7b756) << 12);
	c = d + ((c + fun_f(d, a, b) + x[2] + 0x242070db) << 17);
	b = c + ((b + fun_f(c, d, a) + x[3] + 0xc1bdceee) << 22);
	a = b + ((a + fun_f(b, c, d) + x[4] + 0xf57c0faf) << 7);
	d = a + ((d + fun_f(a, b, c) + x[5] + 0x4787c62a) << 12);
	c = d + ((c + fun_f(d, a, b) + x[6] + 0xa8304613) << 17);
	b = c + ((b + fun_f(c, d, a) + x[7] + 0xfd469501) << 22);
	a = b + ((a + fun_f(b, c, d) + x[8] + 0x698098d8) << 7);
	d = a + ((d + fun_f(a, b, c) + x[9] + 0x8b44f7af) << 12);
	c = d + ((c + fun_f(d, a, b) + x[10] + 0xffff5bb1) << 17);
	b = c + ((b + fun_f(c, d, a) + x[11] + 0x895cd7be) << 22);
	a = b + ((a + fun_f(b, c, d) + x[12] + 0x6b901122) << 7);
	d = a + ((d + fun_f(a, b, c) + x[13] + 0xfd987193) << 12);
	c = d + ((c + fun_f(d, a, b) + x[14] + 0xa679438e) << 17);
	b = c + ((b + fun_f(c, d, a) + x[15] + 0x49b40821) << 22);
	fmd->hash[4] = a;
	fmd->hash[5] = b;
	fmd->hash[6] = c;
	fmd->hash[7] = d;
	stage_two(fmd, x);
}

void	stage_two(t_fmd5 *fmd, unsigned *x)
{
	unsigned a;
	unsigned b;
	unsigned c;
	unsigned d;

	a = fmd->hash[4];
	b = fmd->hash[5];
	c = fmd->hash[6];
	d = fmd->hash[7];
	a = b + ((a + fun_g(b, c, d) + x[1] + 0xf61e2562) << 5);
	d = a + ((d + fun_g(a, b, c) + x[6] + 0xc040b340) << 9);
	c = d + ((c + fun_g(d, a, b) + x[11] + 0x265e5a51) << 14);
	b = c + ((b + fun_g(c, d, a) + x[0] + 0xe9b6c7aa) << 20);
	a = b + ((a + fun_g(b, c, d) + x[5] + 0xd62f105d) << 5);
	d = a + ((d + fun_g(a, b, c) + x[10] + 0x02441453) << 9);
	c = d + ((c + fun_g(d, a, b) + x[15] + 0xd8a1e681) << 14);
	b = c + ((b + fun_g(c, d, a) + x[4] + 0xe7d3fbc8) << 20);
	a = b + ((a + fun_g(b, c, d) + x[9] + 0x21e1cde6) << 5);
	d = a + ((d + fun_g(a, b, c) + x[14] + 0xc33707d6) << 9);
	c = d + ((c + fun_g(d, a, b) + x[3] + 0xf4d50d87) << 14);
	b = c + ((b + fun_g(c, d, a) + x[8] + 0x455a14ed) << 20);
	a = b + ((a + fun_g(b, c, d) + x[13] + 0xa9e3e905) << 5);
	d = a + ((d + fun_g(a, b, c) + x[2] + 0xfcefa3f8) << 9);
	c = d + ((c + fun_g(d, a, b) + x[7] + 0x676f02d9) << 14);
	b = c + ((b + fun_g(c, d, a) + x[12] + 0x8d2a4c8a) << 20);
	fmd->hash[4] = a;
	fmd->hash[5] = b;
	fmd->hash[6] = c;
	fmd->hash[7] = d;
	stage_three(fmd, x);
}

void	stage_three(t_fmd5 *fmd, unsigned *x)
{
	unsigned a;
	unsigned b;
	unsigned c;
	unsigned d;

	a = fmd->hash[4];
	b = fmd->hash[5];
	c = fmd->hash[6];
	d = fmd->hash[7];
	a = b + ((a + fun_h(b, c, d) + x[5] + 0xfffa3942) << 4);
	d = a + ((d + fun_h(a, b, c) + x[8] + 0x8771f681) << 11);
	c = d + ((c + fun_h(d, a, b) + x[11] + 0x6d9d6122) << 16);
	b = c + ((b + fun_h(c, d, a) + x[14] + 0xfde5380c) << 23);
	a = b + ((a + fun_h(b, c, d) + x[1] + 0xa4beea44) << 4);
	d = a + ((d + fun_h(a, b, c) + x[4] + 0x4bdecfa9) << 11);
	c = d + ((c + fun_h(d, a, b) + x[7] + 0xf6bb4b60) << 16);
	b = c + ((b + fun_h(c, d, a) + x[10] + 0xbebfbc70) << 23);
	a = b + ((a + fun_h(b, c, d) + x[13] + 0x289b7ec6) << 4);
	d = a + ((d + fun_h(a, b, c) + x[0] + 0xeaa127fa) << 11);
	c = d + ((c + fun_h(d, a, b) + x[3] + 0xd4ef3085) << 16);
	b = c + ((b + fun_h(c, d, a) + x[6] + 0x04881d05) << 23);
	a = b + ((a + fun_h(b, c, d) + x[9] + 0xd9d4d039) << 4);
	d = a + ((d + fun_h(a, b, c) + x[12] + 0xe6db99e5) << 11);
	c = d + ((c + fun_h(d, a, b) + x[15] + 0x1fa27cf8) << 16);
	b = c + ((b + fun_h(c, d, a) + x[2] + 0xc4ac5665) << 23);
	fmd->hash[4] = a;
	fmd->hash[5] = b;
	fmd->hash[6] = c;
	fmd->hash[7] = d;
	stage_four(fmd, x);
}

void	stage_four(t_fmd5 *fmd, unsigned *x)
{
	unsigned a;
	unsigned b;
	unsigned c;
	unsigned d;

	a = fmd->hash[4];
	b = fmd->hash[5];
	c = fmd->hash[6];
	d = fmd->hash[7];
	a = b + ((a + fun_i(b, c, d) + x[0] + 0xf4292244) << 6);
	d = a + ((d + fun_i(a, b, c) + x[7] + 0x432aff97) << 10);
	c = d + ((c + fun_i(d, a, b) + x[14] + 0xab9423a7) << 15);
	b = c + ((b + fun_i(c, d, a) + x[5] + 0xfc93a039) << 21);
	a = b + ((a + fun_i(b, c, d) + x[12] + 0x655b59c3) << 6);
	d = a + ((d + fun_i(a, b, c) + x[3] + 0x8f0ccc92) << 10);
	c = d + ((c + fun_i(d, a, b) + x[10] + 0xffeff47d) << 15);
	b = c + ((b + fun_i(c, d, a) + x[1] + 0x85845dd1) << 21);
	a = b + ((a + fun_i(b, c, d) + x[8] + 0x6fa87e4f) << 6);
	d = a + ((d + fun_i(a, b, c) + x[15] + 0xfe2ce6e0) << 10);
	c = d + ((c + fun_i(d, a, b) + x[6] + 0xa3014314) << 15);
	b = c + ((b + fun_i(c, d, a) + x[13] + 0x4e0811a1) << 21);
	a = b + ((a + fun_i(b, c, d) + x[4] + 0xf7537e82) << 6);
	d = a + ((d + fun_i(a, b, c) + x[11] + 0xbd3af235) << 10);
	c = d + ((c + fun_i(d, a, b) + x[2] + 0x2ad7d2bb) << 15);
	b = c + ((b + fun_i(c, d, a) + x[9] + 0xeb86d391) << 21);
	fmd->hash[0] += a;
	fmd->hash[1] += b;
	fmd->hash[2] += c;
	fmd->hash[3] += d;
}