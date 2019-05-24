/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:44:23 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/15 10:56:25 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	char			*s;
	unsigned int	i;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (len == 0 || d == s)
		return (dst);
	while (len > 0)
	{
		if (d < s)
		{
			d[i] = s[i];
			i++;
			len--;
		}
		else
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dst);
}
