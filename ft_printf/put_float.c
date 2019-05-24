/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:49:21 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/16 11:49:23 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_float(t_flag *flg, double i, long long int nbr, int prec)
{
	int		len;

	len = get_lnfloat(i, prec);
	ft_putnbrlg(nbr);
	if (flg->hash > 0 || prec >= 0)
		ft_putchar('.');
	if (prec >= 0)
	{
		flg->prec = 0;
		i = (i - nbr) > 0 ? i - nbr : nbr - i;
		if (prec > 0)
			nbr = i * get_precfl(prec) + 0.5;
		else
			nbr = i * 1000000 + 0.5;
		if (ft_strsize_itoa(nbr, 10) < len)
			put_zero(len - ft_strsize_itoa(nbr, 10));
		if (nbr == 0)
		{
			if (prec > 0)
				put_zero(--prec);
			else
				put_zero(5);
		}
		ft_putnbrlg(nbr);
	}
}

int		prep_float(t_flag *flg, long long int nbr, int ret)
{
	if (ft_isnegative(nbr))
	{
		if (flg->space > 0)
			flg->space = 0;
		if (flg->plus > 0)
			flg->plus = 0;
		flg->neg++;
		ret++;
	}
	ret = flg->prec == 0 ? ret + ft_strsize_itoa(nbr, 10) + 7 :
		ret + ft_strsize_itoa(nbr, 10) + flg->prec + 1;
	if (flg->plus > 0 || flg->space > 0 ||
		(flg->hash > 0 && flg->width == 0 && flg->prec < 0))
		ret++;
	if (flg->width > ret)
	{
		flg->len = flg->len + ret;
		ret = flg->width;
	}
	else
		flg->width = 0;
	return (ret);
}

void	put_posfloat(t_flag *flg, double i, int flag, int prec)
{
	long long int	nbr;

	if (flg->neg > 0 && flg->zero > 0 && flg->width > 0)
	{
		ft_putchar('-');
		i = -i;
	}
	nbr = (long long int)i;
	if (flg->width > 0)
	{
		flg->prec = 0;
		put_width(flg);
	}
	if (flg->space > 0)
		ft_putchar(' ');
	if (flg->plus > 0)
		ft_putchar('+');
	if (flag == 1)
		ft_putchar('-');
	put_float(flg, i, nbr, prec);
}

void	put_negfloat(t_flag *flg, double i, int prec)
{
	long long int	nbr;

	nbr = (long long int)i;
	if (flg->space > 0)
		ft_putchar(' ');
	if (flg->plus > 0)
		ft_putchar('+');
	put_float(flg, i, nbr, prec);
	if (flg->width > 0)
		put_width(flg);
}

int		format_float(va_list *list, t_flag *flg)
{
	double			i;
	int				prec;
	int				ret;
	int				flag;

	ret = 0;
	flag = 0;
	prec = flg->prec;
	i = va_arg(*list, double);
	if (i != i)
		return (check_nan(flg, ret));
	else if (i == (1.0 / 0.0) || i == (-1.0 / 0.0))
		return (check_inf(flg, i, ret));
	else if (i == 0 && 1 / i < 0)
	{
		if (flg->prec <= 0 || flg->prec > flg->width)
			ret++;
		flag = check_negzero(flg);
	}
	ret = prep_float(flg, (long long int)i, ret);
	if (flg->minus == 0)
		put_posfloat(flg, i, flag, prec);
	else
		put_negfloat(flg, i, prec);
	return (ret);
}
