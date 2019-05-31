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

unsigned	rl(unsigned a, unsigned b)
{
	return ((a << b) | (a >> (32 - b)));
}

void		stage_one(t_fmd5 *fmd, t_alp *a, unsigned *x)
{
	a->a = fmd->hash[0];
	a->b = fmd->hash[1];
	a->c = fmd->hash[2];
	a->d = fmd->hash[3];
	a->a = a->b + rl((a->a + fun_f(a->b, a->c, a->d) + x[0] + 0xd76aa478), 7);
	a->d = a->a + rl((a->d + fun_f(a->a, a->b, a->c) + x[1] + 0xe8c7b756), 12);
	a->c = a->d + rl((a->c + fun_f(a->d, a->a, a->b) + x[2] + 0x242070db), 17);
	a->b = a->c + rl((a->b + fun_f(a->c, a->d, a->a) + x[3] + 0xc1bdceee), 22);
	a->a = a->b + rl((a->a + fun_f(a->b, a->c, a->d) + x[4] + 0xf57c0faf), 7);
	a->d = a->a + rl((a->d + fun_f(a->a, a->b, a->c) + x[5] + 0x4787c62a), 12);
	a->c = a->d + rl((a->c + fun_f(a->d, a->a, a->b) + x[6] + 0xa8304613), 17);
	a->b = a->c + rl((a->b + fun_f(a->c, a->d, a->a) + x[7] + 0xfd469501), 22);
	a->a = a->b + rl((a->a + fun_f(a->b, a->c, a->d) + x[8] + 0x698098d8), 7);
	a->d = a->a + rl((a->d + fun_f(a->a, a->b, a->c) + x[9] + 0x8b44f7af), 12);
	a->c = a->d + rl((a->c + fun_f(a->d, a->a, a->b) + x[10] + 0xffff5bb1), 17);
	a->b = a->c + rl((a->b + fun_f(a->c, a->d, a->a) + x[11] + 0x895cd7be), 22);
	a->a = a->b + rl((a->a + fun_f(a->b, a->c, a->d) + x[12] + 0x6b901122), 7);
	a->d = a->a + rl((a->d + fun_f(a->a, a->b, a->c) + x[13] + 0xfd987193), 12);
	a->c = a->d + rl((a->c + fun_f(a->d, a->a, a->b) + x[14] + 0xa679438e), 17);
	a->b = a->c + rl((a->b + fun_f(a->c, a->d, a->a) + x[15] + 0x49b40821), 22);
	fmd->hash[4] = a->a;
	fmd->hash[5] = a->b;
	fmd->hash[6] = a->c;
	fmd->hash[7] = a->d;
	stage_two(fmd, a, x);
}

void		stage_two(t_fmd5 *fmd, t_alp *a, unsigned *x)
{
	a->a = fmd->hash[4];
	a->b = fmd->hash[5];
	a->c = fmd->hash[6];
	a->d = fmd->hash[7];
	a->a = a->b + rl((a->a + fun_g(a->b, a->c, a->d) + x[1] + 0xf61e2562), 5);
	a->d = a->a + rl((a->d + fun_g(a->a, a->b, a->c) + x[6] + 0xc040b340), 9);
	a->c = a->d + rl((a->c + fun_g(a->d, a->a, a->b) + x[11] + 0x265e5a51), 14);
	a->b = a->c + rl((a->b + fun_g(a->c, a->d, a->a) + x[0] + 0xe9b6c7aa), 20);
	a->a = a->b + rl((a->a + fun_g(a->b, a->c, a->d) + x[5] + 0xd62f105d), 5);
	a->d = a->a + rl((a->d + fun_g(a->a, a->b, a->c) + x[10] + 0x02441453), 9);
	a->c = a->d + rl((a->c + fun_g(a->d, a->a, a->b) + x[15] + 0xd8a1e681), 14);
	a->b = a->c + rl((a->b + fun_g(a->c, a->d, a->a) + x[4] + 0xe7d3fbc8), 20);
	a->a = a->b + rl((a->a + fun_g(a->b, a->c, a->d) + x[9] + 0x21e1cde6), 5);
	a->d = a->a + rl((a->d + fun_g(a->a, a->b, a->c) + x[14] + 0xc33707d6), 9);
	a->c = a->d + rl((a->c + fun_g(a->d, a->a, a->b) + x[3] + 0xf4d50d87), 14);
	a->b = a->c + rl((a->b + fun_g(a->c, a->d, a->a) + x[8] + 0x455a14ed), 20);
	a->a = a->b + rl((a->a + fun_g(a->b, a->c, a->d) + x[13] + 0xa9e3e905), 5);
	a->d = a->a + rl((a->d + fun_g(a->a, a->b, a->c) + x[2] + 0xfcefa3f8), 9);
	a->c = a->d + rl((a->c + fun_g(a->d, a->a, a->b) + x[7] + 0x676f02d9), 14);
	a->b = a->c + rl((a->b + fun_g(a->c, a->d, a->a) + x[12] + 0x8d2a4c8a), 20);
	fmd->hash[4] = a->a;
	fmd->hash[5] = a->b;
	fmd->hash[6] = a->c;
	fmd->hash[7] = a->d;
	stage_three(fmd, a, x);
}

void		stage_three(t_fmd5 *fmd, t_alp *a, unsigned *x)
{
	a->a = fmd->hash[4];
	a->b = fmd->hash[5];
	a->c = fmd->hash[6];
	a->d = fmd->hash[7];
	a->a = a->b + rl((a->a + fun_h(a->b, a->c, a->d) + x[5] + 0xfffa3942), 4);
	a->d = a->a + rl((a->d + fun_h(a->a, a->b, a->c) + x[8] + 0x8771f681), 11);
	a->c = a->d + rl((a->c + fun_h(a->d, a->a, a->b) + x[11] + 0x6d9d6122), 16);
	a->b = a->c + rl((a->b + fun_h(a->c, a->d, a->a) + x[14] + 0xfde5380c), 23);
	a->a = a->b + rl((a->a + fun_h(a->b, a->c, a->d) + x[1] + 0xa4beea44), 4);
	a->d = a->a + rl((a->d + fun_h(a->a, a->b, a->c) + x[4] + 0x4bdecfa9), 11);
	a->c = a->d + rl((a->c + fun_h(a->d, a->a, a->b) + x[7] + 0xf6bb4b60), 16);
	a->b = a->c + rl((a->b + fun_h(a->c, a->d, a->a) + x[10] + 0xbebfbc70), 23);
	a->a = a->b + rl((a->a + fun_h(a->b, a->c, a->d) + x[13] + 0x289b7ec6), 4);
	a->d = a->a + rl((a->d + fun_h(a->a, a->b, a->c) + x[0] + 0xeaa127fa), 11);
	a->c = a->d + rl((a->c + fun_h(a->d, a->a, a->b) + x[3] + 0xd4ef3085), 16);
	a->b = a->c + rl((a->b + fun_h(a->c, a->d, a->a) + x[6] + 0x04881d05), 23);
	a->a = a->b + rl((a->a + fun_h(a->b, a->c, a->d) + x[9] + 0xd9d4d039), 4);
	a->d = a->a + rl((a->d + fun_h(a->a, a->b, a->c) + x[12] + 0xe6db99e5), 11);
	a->c = a->d + rl((a->c + fun_h(a->d, a->a, a->b) + x[15] + 0x1fa27cf8), 16);
	a->b = a->c + rl((a->b + fun_h(a->c, a->d, a->a) + x[2] + 0xc4ac5665), 23);
	fmd->hash[4] = a->a;
	fmd->hash[5] = a->b;
	fmd->hash[6] = a->c;
	fmd->hash[7] = a->d;
	stage_four(fmd, a, x);
}

void		stage_four(t_fmd5 *fmd, t_alp *a, unsigned *x)
{
	a->a = fmd->hash[4];
	a->b = fmd->hash[5];
	a->c = fmd->hash[6];
	a->d = fmd->hash[7];
	a->a = a->b + rl((a->a + fun_i(a->b, a->c, a->d) + x[0] + 0xf4292244), 6);
	a->d = a->a + rl((a->d + fun_i(a->a, a->b, a->c) + x[7] + 0x432aff97), 10);
	a->c = a->d + rl((a->c + fun_i(a->d, a->a, a->b) + x[14] + 0xab9423a7), 15);
	a->b = a->c + rl((a->b + fun_i(a->c, a->d, a->a) + x[5] + 0xfc93a039), 21);
	a->a = a->b + rl((a->a + fun_i(a->b, a->c, a->d) + x[12] + 0x655b59c3), 6);
	a->d = a->a + rl((a->d + fun_i(a->a, a->b, a->c) + x[3] + 0x8f0ccc92), 10);
	a->c = a->d + rl((a->c + fun_i(a->d, a->a, a->b) + x[10] + 0xffeff47d), 15);
	a->b = a->c + rl((a->b + fun_i(a->c, a->d, a->a) + x[1] + 0x85845dd1), 21);
	a->a = a->b + rl((a->a + fun_i(a->b, a->c, a->d) + x[8] + 0x6fa87e4f), 6);
	a->d = a->a + rl((a->d + fun_i(a->a, a->b, a->c) + x[15] + 0xfe2ce6e0), 10);
	a->c = a->d + rl((a->c + fun_i(a->d, a->a, a->b) + x[6] + 0xa3014314), 15);
	a->b = a->c + rl((a->b + fun_i(a->c, a->d, a->a) + x[13] + 0x4e0811a1), 21);
	a->a = a->b + rl((a->a + fun_i(a->b, a->c, a->d) + x[4] + 0xf7537e82), 6);
	a->d = a->a + rl((a->d + fun_i(a->a, a->b, a->c) + x[11] + 0xbd3af235), 10);
	a->c = a->d + rl((a->c + fun_i(a->d, a->a, a->b) + x[2] + 0x2ad7d2bb), 15);
	a->b = a->c + rl((a->b + fun_i(a->c, a->d, a->a) + x[9] + 0xeb86d391), 21);
	fmd->hash[0] += a->a;
	fmd->hash[1] += a->b;
	fmd->hash[2] += a->c;
	fmd->hash[3] += a->d;
	printf("\n%u%u%u%u\n", fmd->hash[0], fmd->hash[1], fmd->hash[2], fmd->hash[3]);
}
