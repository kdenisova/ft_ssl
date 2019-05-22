/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_of_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:27:14 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/25 11:02:12 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_of_word(char const *str, char c)
{
	int count;

	count = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}
