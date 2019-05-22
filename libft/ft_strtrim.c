/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:45:13 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/22 11:32:44 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	if (!s)
		return (NULL);
	while (ft_iswhitespace(s[index1]))
		index1++;
	index2 = ft_strlen(s);
	while (ft_iswhitespace(s[index2 - 1]))
		index2--;
	if (index2 < index1)
		index2 = index1;
	return (ft_strsub(s, index1, index2 - index1));
}
