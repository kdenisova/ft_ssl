/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:36:52 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/06 10:36:55 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_unsigned(unsigned long long int n, int base)
{
	int						i;
	int						buffer[22];

	i = 0;
	if (n == 0)
		ft_putchar('0');
	while (n)
	{
		buffer[i] = n % base;
		n = n / base;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar('0' + buffer[i]);
		i--;
	}
}

int		print_nbr(t_flag *flg, unsigned long long int n, int ret)
{
	if (flg->minus == 0)
	{
		if (flg->space > 0 && flg->space >= flg->width)
		{
			flg->space = 0;
			ft_putchar(' ');
			ret++;
		}
		ret = put_posfield(flg, n, ret);
	}
	else
		ret = put_negfield(flg, n, ret);
	return (ret);
}

int		get_posprec(t_flag *flg, int ret)
{
	if (flg->prec > 0)
	{
		if (flg->prec > flg->width)
			ft_putchar('+');
		if (flg->prec > flg->len)
			flg->len--;
	}
	else
		ft_putchar('+');
	return (format_int(flg, ret, 1));
}

int		get_negprec(t_flag *flg, int ret)
{
	if (flg->width == 0 && (flg->space > 0 || flg->plus > 0))
	{
		if (flg->space > 0)
		{
			flg->space = 0;
			ft_putchar(' ');
		}
		else if (flg->plus > 0)
			ft_putchar('+');
		ret++;
	}
	else
	{
		ret = flg->width;
		flg->width++;
		if (flg->minus == 0)
			put_width(flg);
		if (flg->plus > 0)
			ft_putchar('+');
		if (flg->minus > 0)
			put_width(flg);
	}
	return (ret);
}

int		get_nbr(t_flag *flg, void *nbr, int ret)
{
	unsigned long long int	n;

	n = *((unsigned long long int *)nbr);
	ret = get_negative(flg, n);
	if (flg->prec == -1 && n == 0)
		return (get_negprec(flg, 0));
	if (flg->neg > 0 && (flg->width <= flg->len || flg->minus > 0
		|| (flg->zero > 0 && flg->prec == 0)))
	{
		flg->neg = 0;
		flg->sign = 1;
		if (flg->md == 0 || flg->width > flg->len || flg->prec > flg->len)
		{
			ft_putchar('-');
			n = -n;
		}
	}
	return (print_nbr(flg, n, ret));
}
