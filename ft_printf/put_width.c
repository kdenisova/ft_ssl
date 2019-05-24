/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:54:36 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/01 13:54:40 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_space(t_flag *flg)
{
	char	c;
	int		count;

	if (flg->zero > 0 && (flg->width <= flg->prec
		|| (flg->width > 0 && flg->prec == 0)))
		c = '0';
	else
		c = ' ';
	count = flg->width - flg->len;
	if (flg->plus > 0 && flg->width > flg->prec
		&& flg->prec >= flg->len)
		count--;
	while (count-- > 0)
		ft_putchar(c);
	if (flg->plus > 0 && flg->width > flg->prec
		&& flg->prec > 0 && flg->minus == 0)
	{
		ft_putchar('+');
		flg->plus = 0;
	}
}

void	put_zero(int zero)
{
	while (zero > 0)
	{
		ft_putchar('0');
		zero--;
	}
}

void	put_width(t_flag *flg)
{
	int		zero;

	zero = 0;
	if (flg->prec < flg->len && flg->zero > 0 && flg->hash > 0 && flg->prec > 0)
		flg->zero = 0;
	if (flg->prec >= flg->width)
	{
		flg->width = flg->prec;
		flg->zero++;
	}
	else if (flg->width > 0 && flg->prec > flg->len)
	{
		zero = flg->prec - flg->len;
		flg->len = flg->prec;
	}
	else if (flg->width > flg->len && flg->hash > 0 && flg->zero > 0)
	{
		put_zero(flg->width - flg->len);
		flg->width = 0;
	}
	put_space(flg);
	put_zero(zero);
	flg->width = 0;
	flg->prec = 0;
}

int		format_unint(t_flag *flg, int ret, unsigned long long int n)
{
	if (flg->hash > 0 && flg->prec < 0 && n == 0)
		ret--;
	if (flg->width > 0 || flg->prec > 0)
	{
		if (flg->width > ret || flg->prec > ret)
		{
			if (flg->width > flg->prec)
				ret = flg->width;
			else
				ret = flg->prec;
		}
		if (flg->prec < 0 && flg->hash > 0 && n == 0)
			flg->len = flg->len - 2;
		if ((flg->width > flg->len || flg->prec > flg->len) && flg->len >= 0)
			put_width(flg);
	}
	return (ret);
}

int		format_string(t_flag *flg)
{
	int	ret;

	if (flg->width > flg->len)
	{
		ret = flg->width;
		put_width(flg);
	}
	else
		ret = flg->len;
	return (ret);
}
