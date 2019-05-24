/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:11:41 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/21 14:42:22 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str(char *str, long nbr, int len)
{
	str[len] = '\0';
	while (nbr)
	{
		str[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = ft_strsize_itoa(n, 10);
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
	return (fill_str(str, nbr, len));
}
