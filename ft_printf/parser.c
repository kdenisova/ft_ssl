/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:30:41 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/09 15:30:43 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_md(t_flag *flg, const char **format)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		flg->md = MD_HH;
		(*format)++;
	}
	else if (**format == 'h')
		flg->md = MD_H;
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		flg->md = MD_LL;
		(*format)++;
	}
	else if (**format == 'l')
		flg->md = MD_L;
	else if (**format == 'L')
		flg->md = MD_BL;
	if (flg->md)
		(*format)++;
	return (0);
}

int		parse_convert(t_flag *flg, const char **format)
{
	while (**format == ' ' || **format == '+' || **format == '-' ||
	**format == '0' || **format == '#')
	{
		if (**format == ' ')
			flg->space++;
		else if (**format == '+')
			flg->plus++;
		else if (**format == '-')
			flg->minus++;
		else if (**format == '0')
			flg->zero++;
		else if (**format == '#')
			flg->hash++;
		(*format)++;
	}
	if (flg->minus != 0)
		flg->zero = 0;
	if (flg->plus != 0)
		flg->space = 0;
	return (1);
}

int		parse_width(const char **format)
{
	int w;

	w = 0;
	while (ft_isdigit(**format))
	{
		w = w * 10 + (**format - '0');
		(*format)++;
	}
	return (w);
}

int		parse_format(va_list *list, const char **format)
{
	t_flag	flg;

	(*format)++;
	fill_list(&flg, format);
	if (**format == 'd' || **format == 'i')
		return (arg_int(list, &flg));
	else if (**format == 'o' || **format == 'u' || **format == 'U'
			|| **format == 'p' || **format == 'x' || **format == 'X')
		return (arg_unint(list, &flg, format));
	else if (**format == 'c' || **format == 'C')
		return (put_char(list, &flg));
	else if (**format == 's' || **format == 'S')
		return (get_string(list, &flg));
	else if (**format == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else if (**format == 'f' || **format == 'F')
		return (format_float(list, &flg));
	else if (**format == 'b')
		return (ft_putbits(va_arg(*list, unsigned int)));
	return (-1);
}

int		arg_int(va_list *list, t_flag *flg)
{
	long long int	nbr;
	int				ret;

	ret = 0;
	if (flg->md == MD_H)
		nbr = (short)va_arg(*list, long long int);
	else if (flg->md == MD_HH)
		nbr = (signed char)va_arg(*list, long long int);
	else if (flg->md == MD_L)
		nbr = (long)va_arg(*list, long long int);
	else if (flg->md == MD_LL)
		nbr = (long long)va_arg(*list, long long int);
	else
		nbr = (int)va_arg(*list, long long int);
	if (flg->plus > 0 && nbr < 0)
		flg->plus = 0;
	return (get_nbr(flg, (void *)(&nbr), ret));
}
