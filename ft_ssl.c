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
	t_fmd5 fmd;
	t_flag flg;
	unsigned *x;

	if (argc < 4)
	{
		ft_putstr("usage: ./ft_ssl [hash_function] [flags] [string]\n");
	}
	else
	{
		flag_init(&flg, argv[1]);
		parse_flag(&flg, argv[2]);
		if(flg.s)
		{
			md5_init(&fmd, argv[3]);
			x = (unsigned *)ft_strnew(16);
			x = (unsigned *)md5_update(&fmd, argv[3]);
			x[15] = 0;
			stage_one(&fmd, x);
			if (flg.q ==0 && flg.r == 0)
			{
				ft_putstr("MD5 (\"");
				ft_putstr(argv[3]);
				ft_putstr("\") = ");
				print_md5(md5_final(&fmd));
			}
			else if (flg.r)
			{
				print_md5(md5_final(&fmd));
				ft_putstr(" \"");
				ft_putstr(argv[4]);
				ft_putstr("\" ");
			}
			else if(flg.q)
				print_md5(md5_final(&fmd));
			printf("\n");
		}
	}
	return (0);
}
