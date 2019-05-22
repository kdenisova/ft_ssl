/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:25:10 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/20 15:35:21 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		if (find[0] == str[i])
		{
			j = 1;
			while (find[j] != '\0' && str[i + j] == find[j]
					&& (i + j) < len)
			{
				j++;
			}
			if (find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
