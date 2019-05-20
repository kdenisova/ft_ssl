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

unsigned	fun_f(unsigned abcd[])
{
	return ((abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]));
}

unsigned	fun_g(unsigned abcd[])
{
	return ((abcd[1] & abcd[2]) | (~abcd[3] & abcd[2]));
}

unsigned	fun_h(unsigned abcd[])
{
	return (abcd[1] ^ abcd[2] ^ abcd[3]);
}

unsigned	fun_i(unsigned abcd[])
{
	return (abcd[2] ^ (~abcd[3] | abcd[1]));
}
