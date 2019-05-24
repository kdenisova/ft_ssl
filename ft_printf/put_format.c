/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:27:52 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/09 15:27:58 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prep_unint(t_flag *flg, const char **format, void *nbr)
{
	unsigned long long int	n;
	int						ret;

	ret = 0;
	n = *((unsigned long long int *)nbr);
	if ((**format == 'o' && flg->hash > 0 && n == 0 && flg->prec >= 0)
		|| (flg->hash > 0 && n == 0 && (**format == 'x' || **format == 'X')))
		flg->hash = 0;
	if (**format == 'o')
		flg->base = 8;
	else if (**format == 'x' || **format == 'X' || **format == 'p')
		flg->base = 16;
	if ((flg->hash == 1 && (**format == 'o' || **format == 'x'
		|| **format == 'X')) || **format == 'p')
		ret = get_altr(flg, format, n);
	if (flg->len > ret)
		ret = flg->len;
	else if (flg->len == 0)
	{
		flg->len = ft_strsize_itoa_un(n, flg->base);
		ret = flg->len;
	}
	return (ret);
}

int		put_zunint(t_flag *flg, unsigned long long int n, int ret)
{
	if (flg->width == 0)
		ret--;
	else
	{
		if (flg->hash == 0)
			flg->len = 0;
		else
			flg->len++;
		ret = format_unint(flg, ret, n);
	}
	return (ret);
}

void	put_hex(t_flag *flg, const char **format, unsigned long long int n)
{
	char *str;

	if (**format == 'X')
	{
		if (flg->md == MD_LL || flg->md == MD_L)
			str = ft_strtoupper(ft_itoa_un(n, flg->base));
		else
			str = ft_strtoupper(ft_itoa_base(n, flg->base));
	}
	else
	{
		if (flg->md == MD_LL || flg->md == MD_L)
			str = ft_itoa_un(n, flg->base);
		else
			str = ft_itoa_base(n, flg->base);
	}
	ft_putstr(str);
	ft_strdel(&str);
}

void	put_unint(t_flag *flg, const char **format, unsigned long long int n)
{
	char *str;

	if (**format == 'x' || **format == 'X')
		put_hex(flg, format, n);
	else
	{
		if ((flg->md == MD_LL || flg->md == MD_L) && **format != 'p')
			put_unsigned(n, flg->base);
		else
		{
			str = ft_itoa_base(n, flg->base);
			ft_putstr(str);
			ft_strdel(&str);
		}
	}
}

int		get_unint(t_flag *flg, const char **format, void *nbr)
{
	unsigned long long int	n;
	int						ret;

	n = *((unsigned long long int *)nbr);
	ret = prep_unint(flg, format, nbr);
	if (flg->prec == -1 && n == 0)
		return (put_zunint(flg, n, ret));
	if (flg->minus == 0)
	{
		ret = format_unint(flg, ret, n);
		put_unint(flg, format, n);
	}
	else
	{
		if (flg->prec > flg->len)
		{
			put_zero(flg->prec - flg->len);
			flg->len = flg->prec;
			ret = flg->len;
			flg->prec = 0;
		}
		put_unint(flg, format, n);
		ret = format_unint(flg, ret, n);
	}
	return (ret);
}
