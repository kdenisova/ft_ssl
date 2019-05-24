/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:30:51 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/06 10:31:06 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_nan(t_flag *flg, int ret)
{
	if (flg->width <= 3)
	{
		ft_putstr("nan");
		ret = 3;
	}
	else
	{
		flg->len = 3;
		flg->zero = 0;
		flg->plus = 0;
		ret = flg->width;
		if (flg->minus == 0)
		{
			put_space(flg);
			ft_putstr("nan");
		}
		else
		{
			ft_putstr("nan");
			put_space(flg);
		}
	}
	return (ret);
}

int				check_inf(t_flag *flg, double i, int ret)
{
	if (flg->width <= 3)
		ret = put_inf(flg, ret, i);
	else
	{
		flg->len = 3;
		flg->zero = 0;
		flg->prec = 0;
		ret = flg->width;
		if (flg->space > 0 || flg->plus > 0 || i < 0)
			flg->len++;
		if (flg->minus == 0)
		{
			put_space(flg);
			put_inf(flg, ret, i);
		}
		else
		{
			put_inf(flg, ret, i);
			put_space(flg);
		}
	}
	return (ret);
}

int				check_negzero(t_flag *flg)
{
	flg->space = 0;
	flg->plus = 0;
	flg->len++;
	if (flg->width == 0 || flg->minus > 0 || flg->zero > 0)
		ft_putchar('-');
	else
		return (1);
	return (0);
}

int				get_lnfloat(double n, int prec)
{
	int		len;
	int		nbr;
	double	temp;

	if (n < 0)
		n = n * (-1);
	len = 0;
	if (n == 0)
		return (1);
	nbr = (int)n;
	temp = n - nbr;
	if (prec > 0)
		nbr = temp * get_precfl(prec);
	else
		nbr = temp * 1000000;
	while (temp < nbr)
	{
		temp = temp * 10;
		len++;
	}
	return (len);
}

long long int	get_precfl(int pr)
{
	long long int	prec;

	prec = 1;
	while (pr > 0)
	{
		prec = prec * 10;
		pr--;
	}
	return (prec);
}
