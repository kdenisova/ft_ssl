/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_md5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:07:07 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/20 11:07:10 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned	fun_f(unsigned x, unsigned y, unsigned z)
{
	return ((x & y) | (~x & z));
}

unsigned	fun_g(unsigned x, unsigned y, unsigned z)
{
	return ((x & z) | (~z & y));
}

unsigned	fun_h(unsigned x, unsigned y, unsigned z)
{
	return (x ^ y ^ z);
}

unsigned	fun_i(unsigned x, unsigned y, unsigned z)
{
	return (y ^ (~z | x));
}
