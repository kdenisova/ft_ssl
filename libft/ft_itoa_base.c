/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:26:52 by kdenisov          #+#    #+#             */
/*   Updated: 2019/03/28 14:26:54 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert_base(char *str, long nbr, int len, int base)
{
	str[len] = '\0';
	while (nbr)
	{
		str[--len] = HEX[nbr % base];
		nbr = nbr / base;
	}
	return (str);
}

char		*ft_itoa_base(long n, int base)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = ft_strsize_itoa(n, base);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
		str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		*str = '0';
		return (str);
	}
	return (ft_convert_base(str, nbr, len, base));
}
