/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:29:56 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/10 11:29:58 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_un(unsigned long long int nbr, int base)
{
	int		len;
	char	*str;

	len = ft_strsize_itoa_un(nbr, base);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (nbr == 0)
	{
		*str = '0';
		return (str);
	}
	str[len] = '\0';
	while (nbr)
	{
		str[--len] = HEX[nbr % base];
		nbr = nbr / base;
	}
	return (str);
}
