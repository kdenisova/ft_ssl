/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:49:02 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/20 11:50:10 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int				i;
	int				buffer[10];
	unsigned int	unb;

	i = 0;
	unb = n;
	if (n < 0)
	{
		unb = -unb;
		ft_putchar('-');
	}
	if (n == 0)
		ft_putchar('0');
	while (unb)
	{
		buffer[i] = unb % 10;
		unb = unb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar('0' + buffer[i]);
		i--;
	}
}
