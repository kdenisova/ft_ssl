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

void	put_hash(unsigned *hash)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", hash[i]);
		i++;
	}
}

void	put_md5(t_flg *flg, t_fmd5 *fmd, char *arg)
{
	if (flg->in)
	{
		if (flg->p)
			ft_printf("%s", arg);
		put_hash(md5_final(fmd));
	}
	else if (flg->q == 0 && flg->r == 0)
	{
		if (flg->s)
			ft_printf("MD5 (\"%s\") = ", arg);
		else
			ft_printf("MD5 (%s) = ", flg->fdname);
		put_hash(md5_final(fmd));
	}
	else if (flg->r)
	{
		put_hash(md5_final(fmd));
		if (flg->s)
			ft_printf(" \"%s\"", arg);
		else
			ft_printf(" %s", flg->fdname);
	}
	else if (flg->q)
		put_hash(md5_final(fmd));
	ft_putchar('\n');
}

void	put_hash_sha512(t_fsha *fsh)
{
	int i;

	i = 0;
	while (i < fsh->hash_len)
	{
		ft_printf("%016lx", fsh->hash[i]);
		i++;
	}
}

void	put_hash_sha256(t_fsha *fsh)
{
	int i;

	i = 0;
	while (i < fsh->hash_len)
	{
		ft_printf("%08x", fsh->hash[i]);
		i++;
	}
}

void	put_sha_s(t_flg *flg, t_fsha *fsh, char *arg, void (*f_put)(t_fsha *))
{
	char *alg;

	alg = ft_strdup(flg->alg);
	if (flg->s)
		ft_printf("%s(\"%s\")= ", ft_strtoupper(alg), arg);
	else
		ft_printf("%s(%s)= ", ft_strtoupper(alg), flg->fdname);
	(*f_put)(fsh);
	free(alg);
}

void	put_sha(t_flg *flg, t_fsha *fsh, char *arg, void (*f_put)(t_fsha *))
{
	if (flg->in)
	{
		if (flg->p)
			ft_printf("%s", arg);
		(*f_put)(fsh);
	}
	else if (flg->q == 0 && flg->r == 0)
		put_sha_s(flg, fsh, arg, f_put);
	else if (flg->r)
	{
		(*f_put)(fsh);
		if (flg->s)
			ft_printf(" \"%s\"", arg);
		else
			ft_printf(" %s", flg->fdname);
	}
	else if (flg->q)
		(*f_put)(fsh);
	ft_putchar('\n');
}
