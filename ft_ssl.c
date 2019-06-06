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

int	parse_file(t_fmd5 *fmd, t_flg *flg, t_alp *al, char *arg)
{
	char *line;
	char *str;
	int fd;
	int ret;
	
	fd = open(arg, O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd < 0)
	{
		if (errno == 21)
			ft_printf("%s: %s: Is a directory\n", flg->alg, arg);
		else
			ft_printf("%s: %s: No such file or directory\n", flg->alg, arg);
		exit (1);
	}
	else
	{
		line = ft_strnew(BLOCK_SIZE);
		while ((ret = read(fd, line, BLOCK_SIZE)) > 0)
		{
			str = ft_strjoin(str, line);
			ft_strdel(&line);
			if (ret == BLOCK_SIZE)
				line = ft_strnew(BLOCK_SIZE);
		}
		if (line)
			ft_strdel(&line);
		close(fd);
		if (!ft_strcmp(flg->alg, "md5"))
			ft_md5(fmd, flg, al, str);
		else
			ft_sha(flg, al, str);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fmd5	fmd;
	t_flg	flg;
	t_alp	al;

	if (argc < 2)
	{
		ft_putstr("usage: ./ft_ssl [hash_function] [-pqr] [-s string] [files ...]\n");
		exit(1);
	}
	else
	{
		parse_alg(&flg, argv[1]);
		flag_init(&flg, argv[2]);
		parse_flag(&flg, argv[3]);
		alphabet_init(&al);
		if (flg.s && argv[flg.i])
		{
			if (!ft_strcmp(flg.alg, "md5"))
				ft_md5(&fmd, &flg, &al, argv[flg.i]);
			else
				ft_sha(&flg, &al, argv[flg.i]);
		}
		if (flg.s && !argv[flg.i])
		{
			ft_printf("%s: option requires an argument -- s\n", flg.alg);
			ft_printf("usage: ./ft_ssl [hash_function] [-pqr] [-s string] [files ...]\n");
			exit(1);
		}
		else if (argv[flg.i])
			parse_file(&fmd, &flg, &al, argv[flg.i]);
		else
		{
			ft_printf("usage: ./ft_ssl [hash_function] [-pqr] [-s string] [files ...]\n");
			exit(1);
		}
	}
	//while (1);
	return (0);
}
