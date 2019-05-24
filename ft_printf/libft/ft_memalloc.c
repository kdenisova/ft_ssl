/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:45:59 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/18 11:16:17 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str;
	unsigned char i;

	i = 0;
	str = (unsigned char *)malloc(size);
	if (!str)
		return (NULL);
	else
		ft_memset((void *)str, 0, size);
	return ((void *)str);
}
