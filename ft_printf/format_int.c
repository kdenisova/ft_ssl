/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:25:42 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/01 14:25:44 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_lnint(t_flag *flg, unsigned long long int n)
{
	flg->len = flg->len + ft_strsize_itoa(n, flg->base);
	if (flg->plus > 0 || flg->neg > 0)
		flg->len++;
	if (flg->prec >= flg->len && flg->zero > 0)
		flg->zero = 0;
}

void	put_sign(t_flag *flg)
{
	if (flg->neg > 0)
		ft_putchar('-');
	else
	{
		ft_putchar('+');
		flg->plus = 0;
	}
}

int		put_plus(t_flag *flg, int ret)
{
	if (flg->space > 0)
	{
		flg->len++;
		ret = flg->len;
		ft_putchar(' ');
	}
	if (flg->plus > 0)
		ft_putchar('+');
	return (ret);
}

int		get_negative(t_flag *flg, unsigned long long int n)
{
	int	ret;

	ret = 0;
	if (ft_isnegative(n))
	{
		flg->neg++;
		if (flg->space > 0)
			flg->space = 0;
	}
	get_lnint(flg, n);
	ret = ret + flg->len;
	return (ret);
}

int		format_int(t_flag *flg, int ret, int flag)
{
	if (flg->width > flg->len || flg->prec > flg->len)
	{
		if (flg->width > flg->prec && flg->width > ret)
			ret = flg->width;
		else if (flg->prec > ret)
			ret = flg->prec + flag;
		if (flg->prec > flg->width && flg->sign == 1)
		{
			ret++;
			flg->len--;
		}
	}
	put_width(flg);
	return (ret);
}
