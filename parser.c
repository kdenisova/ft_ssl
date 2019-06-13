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

void	flag_init(t_flg *flg, char **arg, int argv)
{
	int i;

	i = 2;
	flg->p = 0;
	flg->q = 0;
	flg->r = 0;
	flg->s = 0;
	flg->i = 0;
	flg->fd = 0;
	flg->in = 0;
	while (i < argv)
	{
		if (arg[i][0] == '-')
		{
			parse_flag(flg, arg[i]);
			i++;
		}
		else
			break;
	}
	flg->i = i;
	if (!flg->p && !flg->s && argv > 2)
		flg->fd = 1;
	//printf("p = %d, q = %d, r = %d, s = %d, i = %d\n", flg->p, flg->q, flg->r, flg->s, flg->i);
	// else
	// {
	// 	ft_putstr("usage: md5 [-pqr] [-s string] [files ...]\n");
	// 	// ft_putstr("\t-p: echo STDIN to STDOUT and append the checksum ");
	// 	// ft_putstr("to STDOUT\n");
	// 	// ft_putstr("\t-q: quiet mode\n");
	// 	// ft_putstr("\t-r: reverse the format of the output\n");
	// 	// ft_putstr("\t-s: print the sum of the given string\n");
	// 	exit(1);
	// }
}

void	alphabet_init(t_alp *al)
{
	al->a = 0;
	al->b = 0;
	al->c = 0;
	al->d = 0;
	al->e = 0;
	al->f = 0;
	al->g = 0;
	al->h = 0;
}

void	parse_alg(t_flg *flg, char *arg)
{
	if (!ft_strcmp(arg, "md5") || !ft_strcmp(arg, "MD5"))
		flg->alg = "md5";
	else if (!ft_strcmp(arg, "sha256") || !ft_strcmp(arg, "SHA256"))
		flg->alg = "sha256";
	else if (!ft_strcmp(arg, "sha512") || !ft_strcmp(arg, "SHA512"))
		flg->alg = "sha512";
	else
	{
		ft_printf("ft_ssl: Error: \'%s\' is an invalid command.\n\n", arg);
		ft_putstr("Standard commands:\n\nMessage Digest commands:\n");
		ft_putstr("md5\nsha256\nsha512\n\n");
		ft_putstr("Cipher commands:\n");
		exit(1);
	}
}

void	parse_flag(t_flg *flg, char *arg)
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
		flg->fd = 1;
	// if (!flg->q && !flg->r && !flg->p)
	// 	flg->i = 2;
	// else if ((flg->q || flg->r) && !ft_strcmp(arg, "-s"))
	// {
	// 	flg->s = 1;
	// 	flg->i = 4;
	// }
	// else
	// 	flg->i = 3;
}
