/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:52:11 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/22 13:35:41 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int				flag;
	unsigned int	len;

	len = 0;
	flag = 0;
	while (*dest && len < size)
	{
		dest++;
		len++;
	}
	while (*src)
	{
		if (len < size - 1 && size != 0)
		{
			*dest = *src;
			flag = 1;
			dest++;
		}
		len++;
		src++;
	}
	if (flag == 1)
		*dest = '\0';
	return (len);
}
