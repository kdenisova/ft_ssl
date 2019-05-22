/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:46:34 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/15 15:05:18 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sym;

	sym = c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == sym)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
