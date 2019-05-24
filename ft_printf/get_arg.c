/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:27:31 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/03 13:27:33 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		arg_unint(va_list *list, t_flag *flg, const char **format)
{
	unsigned long long int	nbr;

	if (flg->md == MD_H)
		nbr = (unsigned short)va_arg(*list, unsigned long long int);
	else if (flg->md == MD_HH)
		nbr = (unsigned char)va_arg(*list, unsigned long long int);
	else if (flg->md == MD_L || **format == 'p')
		nbr = (unsigned long)va_arg(*list, unsigned long long int);
	else if (flg->md == MD_LL)
		nbr = (unsigned long long)va_arg(*list, unsigned long long int);
	else
		nbr = (unsigned int)va_arg(*list, unsigned int);
	return (get_unint(flg, format, (void *)(&nbr)));
}

void	put_altr(const char **format)
{
	if (**format == 'o')
		ft_putchar('0');
	else if (**format == 'X')
		ft_putstr("0X");
	else
		ft_putstr("0x");
}

int		put_altpos(t_flag *flg, const char **format, int ret)
{
	if (flg->prec > ret)
		ret = flg->prec;
	if (**format == 'o' || flg->width > flg->prec)
	{
		put_width(flg);
		put_altr(format);
		flg->prec = -1;
	}
	else
	{
		flg->prec = flg->prec + 2;
		ret = flg->prec;
		put_altr(format);
		put_width(flg);
	}
	return (ret);
}

int		get_altr(t_flag *flg, const char **format, unsigned long long int nbr)
{
	int ret;

	flg->len++;
	if (**format == 'x' || **format == 'X' || **format == 'p')
		flg->len++;
	flg->len = flg->len + ft_strsize_itoa_un(nbr, flg->base);
	ret = flg->width > flg->len ? flg->width : flg->len;
	if (flg->zero == 0 && flg->minus == 0)
	{
		if (flg->prec == 0 && flg->width == 0)
			put_altr(format);
		else
			ret = put_altpos(flg, format, ret);
	}
	else if (flg->width > flg->len && flg->minus == 0 && flg->prec > 0)
	{
		put_width(flg);
		put_altr(format);
	}
	else
		put_altr(format);
	return (ret);
}

int		put_inf(t_flag *flg, int ret, double i)
{
	ret = 3;
	if (flg->space > 0 || flg->plus > 0 || i < 0)
	{
		ret++;
		if (i < 0)
		{
			ft_putchar('-');
			flg->space = 0;
			flg->plus = 0;
		}
		else if (flg->space > 0)
			ft_putchar(' ');
		else if (flg->plus > 0)
			ft_putchar('+');
	}
	ft_putstr("inf");
	return (ret);
}
