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

int		check_error(t_flg *flg, char *arg, int fd)
{
	struct stat	statbuf;

	fstat(fd, &statbuf);
	if (S_ISDIR(statbuf.st_mode))
	{
		ft_printf("%s: %s: Is a directory\n", g_name[flg->index], arg);
		return (-1);
	}
	if (fd < 0)
		ft_printf("%s: %s: No such file or directory\n", g_name[flg->index], arg);
	return (fd);
}

int		parse_file(t_flg *flg, t_alp *al, char *arg)
{
	char		line[BLOCK_SIZE + 1];
	char		*str;
	char		*temp;
	int			len;
	int			fd;

	len = 0;
	fd = open(arg, O_RDONLY);
	if (check_error(flg, arg, fd) < 0)
		return (1);
	else
	{
		flg->fdname = arg;
		str = ft_strnew(1);
		while ((len = read(fd, line, BLOCK_SIZE)) > 0)
		{
			line[len] = '\0';
			temp = ft_strjoin(str, line);
			ft_strdel(&str);
			str = temp;
		}
		close(fd);
		g_disp[flg->index](flg, al, str, len);
		ft_strdel(&temp);
	}
	return (0);
}

void	parse_stdin(t_flg *flg, t_alp *al)
{
	char	line[BLOCK_SIZE + 1];
	char	*str;
	char	*temp;
	int		len;

	len = 0;
	flg->in = 1;
	str = ft_strnew(1);
	len = read(0, line, BLOCK_SIZE);
	while (len > 0)
	{
		line[len] = '\0';
		temp = ft_strjoin(str, line);
		ft_strdel(&str);
		str = temp;
		len = read(0, line, BLOCK_SIZE);
	}
	g_disp[flg->index](flg, al, str, len);
	ft_strdel(&temp);
	flg->in = 0;
}

void	parse_str(t_flg *flg, t_alp *al, char **argv)
{
	if (argv[flg->i])
	{
		g_disp[flg->index](flg, al, argv[flg->i], 0);
		flg->s = 0;
		flg->i++;
	}
	else
	{
		ft_printf("%s: option requires an argument -- s\n", g_name[flg->index]);
		ft_printf("usage: ./ft_ssl command [-pqr] [-s string] [files ...]\n");
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	t_flg	flg;
	t_alp	al;

	if (argc < 2)
	{
		ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
		exit(1);
	}
	else
	{
		parse_alg(&flg, &al, argc, argv);
		if (flg.p || argc == 2)
			parse_stdin(&flg, &al);
		if (flg.s)
			parse_str(&flg, &al, argv);
		if (flg.fd)
		{
			while (flg.i < argc)
			{
				parse_file(&flg, &al, argv[flg.i]);
				flg.i++;
			}
		}
	}
	//system("leaks ft_ssl");
	return (0);
}
