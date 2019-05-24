/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:39:05 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/06 10:39:13 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_char(va_list *list, t_flag *flg)
{
	int	i;
	int	ret;

	i = va_arg(*list, int);
	flg->len++;
	if (flg->minus == 0)
	{
		ret = format_string(flg);
		ft_putchar(i);
	}
	else
	{
		ft_putchar(i);
		ret = format_string(flg);
	}
	return (ret);
}

int		put_string(t_flag *flg, char *s)
{
	int		i;
	int		ret;

	i = 0;
	if (flg->minus == 0)
	{
		ret = format_string(flg);
		while (i < flg->len)
			ft_putchar(s[i++]);
	}
	else
	{
		while (i < flg->len)
			ft_putchar(s[i++]);
		ret = format_string(flg);
	}
	return (ret);
}

int		get_string(va_list *list, t_flag *flg)
{
	char	*s;

	s = va_arg(*list, char *);
	if (!s)
		s = "(null)\0";
	flg->len = ft_strlen(s);
	if (flg->prec < flg->len && flg->prec != 0)
		flg->len = flg->prec;
	else if (flg->prec > flg->len)
		flg->prec = flg->len;
	return (put_string(flg, s));
}
