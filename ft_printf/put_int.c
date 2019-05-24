/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:25:14 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/10 13:25:16 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_int(long nbr)
{
	int	i;
	int	buffer[10];

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
	}
	if (nbr == 0)
		ft_putchar('0');
	while (nbr)
	{
		buffer[i] = nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar('0' + buffer[i]);
		i--;
	}
}

int		get_posfield(t_flag *flg, int ret)
{
	int prec;

	if (flg->width > flg->len && flg->width > ret)
		ret = flg->width;
	else
		ret = flg->len;
	if (flg->prec <= flg->len)
	{
		put_width(flg);
		if (flg->plus > 0 || flg->neg > 0)
			put_sign(flg);
	}
	else
	{
		prec = flg->prec;
		flg->width = flg->width - flg->prec + 1;
		flg->prec = 0;
		put_width(flg);
		if (flg->plus > 0 || flg->neg > 0)
			put_sign(flg);
		flg->prec = prec + 1;
		put_width(flg);
	}
	return (ret);
}

int		put_posfield(t_flag *flg, unsigned long long int n, int ret)
{
	if (flg->space > 0)
	{
		ret = flg->width;
		flg->width--;
		ft_putchar(' ');
	}
	if (flg->width > flg->prec && flg->zero == 0
		&& (flg->plus > 0 || flg->neg > 0))
	{
		ret = get_posfield(flg, ret);
		if (flg->neg > 0)
		{
			flg->sign = 1;
			flg->neg = 0;
			n = -n;
		}
	}
	else if (flg->plus > 0 || (flg->plus > 0 && flg->prec > 0))
		ret = get_posprec(flg, ret);
	else
		ret = format_int(flg, ret, 0);
	put_nbr(flg, n);
	return (ret);
}

void	put_nbr(t_flag *flg, unsigned long long int n)
{
	char *str;

	if (flg->neg > 0 && flg->md == 0)
		ft_putchar('-');
	if (flg->md == 0)
		put_int(n);
	else if (flg->md == MD_LL || flg->md == MD_L)
		ft_putnbrlg(n);
	else
	{
		str = ft_itoa_base(n, 10);
		ft_putstr(str);
		ft_strdel(&str);
	}
}

int		put_negfield(t_flag *flg, unsigned long long int n, int ret)
{
	ret = flg->plus > 0 || flg->space > 0 ? put_plus(flg, ret) : ret;
	if (flg->prec > flg->len)
	{
		ret = flg->prec + 1;
		if (flg->sign == 1)
			flg->prec++;
		if (flg->plus > 0 || flg->space > 0)
		{
			put_zero(flg->prec - flg->len + 1);
			flg->len = flg->prec + 1;
		}
		else
		{
			put_zero(flg->prec - flg->len);
			flg->len = flg->prec;
		}
		flg->prec = 0;
	}
	put_nbr(flg, n);
	if (flg->width > flg->len)
	{
		ret = flg->width;
		put_width(flg);
	}
	return (ret);
}
