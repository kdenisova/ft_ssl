/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:47:36 by kdenisov          #+#    #+#             */
/*   Updated: 2019/03/28 11:48:28 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_list(t_flag *flg, const char **format)
{
	flg->md = 0;
	flg->len = 0;
	flg->base = 10;
	flg->space = 0;
	flg->plus = 0;
	flg->minus = 0;
	flg->zero = 0;
	flg->hash = 0;
	flg->neg = 0;
	flg->prec = 0;
	flg->sign = 0;
	parse_convert(flg, format);
	flg->width = parse_width(format);
	if (**format == '.')
	{
		(*format)++;
		flg->prec = parse_width(format);
		if (flg->prec == 0)
		{
			flg->prec = -1;
			flg->zero = 0;
		}
	}
	parse_md(flg, format);
}

int		ft_printf(const char *format, ...)
{
	va_list	list;
	int		ret;
	int		buf;

	ret = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			ret++;
		}
		else
		{
			buf = parse_format(&list, &format);
			if (buf == -1)
				return (-1);
			else
				ret = ret + buf;
		}
		format++;
	}
	va_end(list);
	return (ret);
}
