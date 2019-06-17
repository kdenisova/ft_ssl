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
	else if (!ft_strncmp(arg, "-", 1) && arg[1])
	{
		ft_printf("%s: illegal option -- %c\n", flg->alg, arg[1]);
		ft_printf("usage: ft_ssl ");
		ft_printf("%s [-pqr] [-s string] [files ...]\n", flg->alg);
		exit(1);
	}
	else
		flg->fd = 1;
}

void	flag_init(t_flg *flg, char **arg, int argv)
{
	int i;

	i = 1;
	flg->p = 0;
	flg->q = 0;
	flg->r = 0;
	flg->s = 0;
	flg->i = 0;
	flg->fd = 0;
	flg->in = 0;
	while (++i < argv)
	{
		if (arg[i][0] == '-')
			parse_flag(flg, arg[i]);
		else
			break ;
	}
	flg->i = i;
	if ((!flg->p && !flg->s && arg[i]) || (flg->p && !flg->s && arg[i])
		|| (i != argv - 1))
		flg->fd = 1;
	if (flg->r && flg->q)
		flg->r = 0;
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

int		parse_alg(t_flg *flg, char *arg)
{
	char *alg;

	flg->index = 0;
	alg = ft_strdup(arg);
	ft_strtolower(alg);
	while (flg->index < NBR_CMD && ft_strcmp(g_name[flg->index], alg))
		flg->index++;
	if (flg->index != NBR_CMD)
		flg->alg = ft_strdup(alg);
	else
	{
		ft_printf("ft_ssl: Error: \'%s\' is an invalid command.\n\n", arg);
		ft_putstr("Standard commands:\n\nMessage Digest commands:\n");
		ft_putstr("md5\nsha256\nsha512\n\n");
		ft_putstr("Cipher commands:\n");
		exit(1);
	}
	free(alg);
	return (flg->index);
}
