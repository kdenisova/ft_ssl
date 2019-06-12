/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_sha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:11:51 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/30 13:11:53 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned		rotr(unsigned x, unsigned n)
{
	return ((x >> n) | (x << (32 - n)));
}

unsigned long	rotr_64(unsigned long x, unsigned long n)
{
	return ((x >> n) | (x << (64 - n)));
}

unsigned		revers_bits(unsigned b)
{
	return ((b >> 24) | ((b & 0xFF0000) >> 8) |
		((b & 0xFF00) << 8) | (b << 24));
}

unsigned long	revers_bits_64(unsigned long i)
{
	return (((i & 0x00000000000000FF) << 56)
		| ((i & 0x000000000000FF00) << 40)
		| ((i & 0x0000000000FF0000) << 24)
		| ((i & 0x00000000FF000000) << 8)
		| ((i & 0x000000FF00000000) >> 8)
		| ((i & 0x0000FF0000000000) >> 24)
		| ((i & 0x00FF000000000000) >> 40)
		| ((i & 0xFF00000000000000) >> 56));
}
