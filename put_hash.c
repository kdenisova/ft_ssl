/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 12:21:48 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/07 12:21:52 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			put_md5(t_flg *flg, t_fmd5 *fmd, char *arg)
{
	int			i;

	i = 0;
	if (flg->q == 0 && flg->r == 0)
	{
		if (flg->fd)
			ft_printf("MD5 (%s) = ", flg->fdname);
		else
			ft_printf("MD5 (\"%s\") = ", arg);
		put_hash(md5_final(fmd));
	}
	else if (flg->r)
	{
		put_hash(md5_final(fmd));
		ft_printf(" \"%s\"", arg);
	}
	else if (flg->q)
		put_hash(md5_final(fmd));
	ft_putchar('\n');
}

void			put_hash(unsigned *hash)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", hash[i]);
		i++;
	}
}
