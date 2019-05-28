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

int				main(int argc, char **argv)
{
	t_fmd5	fmd;
	t_flg	flg;
	t_alp	al;

	if (argc < 4)
	{
		ft_putstr("usage: ./ft_ssl [hash_function] usage: [-pqr] [-s string] [files ...]\n");
		exit(1);
	}
	else
	{
		parse_alg(&flg,argv[1]);
		flag_init(&flg, argv[2]);
		parse_flag(&flg, argv[3]);
		alphabet_init(&al);
		if(flg.s && argv[flg.i])
		{
			if (!ft_strcmp(flg.alg, "md5"))
				ft_md5(&fmd, &flg, &al, argv[flg.i]);
			else
				ft_sha(&fmd, &flg, &al, argv[flg.i]);
		}
		else
		{
			ft_printf("%s: option requires an argument -- s\n", flg.alg);
			ft_printf("usage: ./ft_ssl [hash_function] [-pqr] [-s string] [files ...]\n");
			exit(1);
		}
	}
	return (0);
}
