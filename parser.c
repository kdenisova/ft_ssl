/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:21:28 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/24 11:21:30 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	flag_init(t_flag *flg, char *arg)
{
	flg->p = 0;
	flg->q = 0;
	flg->r = 0;
	flg->s = 0;
	if (!ft_strcmp(arg, "md5") || !ft_strcmp(arg, "MD5"))
		flg->alg = "MD5";
	else if (!ft_strcmp(arg, "sha256") || !ft_strcmp(arg, "SHA256"))
		flg->alg = "SHA256";
	else if (!ft_strcmp(arg, "sha512") || !ft_strcmp(arg, "SHA512"))
		flg->alg = "SHA512";
	else
	{
		ft_putstr("Error. Invalid hash function. Use md5, sha256 or sha512\n");
		exit(1);
	}
}

void	parse_flag(t_flag *flg, char *arg)
{
	if (!ft_strcmp(arg, "-p"))
		flg->p = 1;
	else if (!ft_strcmp(arg, "-q"))
		flg->q = 1;
	else if (!ft_strcmp(arg, "-r"))
		flg->r = 1;
	else if (!ft_strcmp(arg, "-s"))
		flg->s = 1;
	else
	{
		ft_putstr("Error. Invalid flag. Use the following flags:\n");
		ft_putstr("\t-p: echo STDIN to STDOUT and append the checksum ");
		ft_putstr("to STDOUT\n");
		ft_putstr("\t-q: quiet mode\n");
		ft_putstr("\t-r: reverse the format of the output\n");
		ft_putstr("\t-s: print the sum of the given string\n");
		exit(1);
	}
}
