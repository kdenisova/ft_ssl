/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:33:02 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/20 13:35:41 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	int				buffer[10];
	unsigned int	unb;

	i = 0;
	unb = n;
	if (n < 0)
	{
		unb = -unb;
		ft_putchar_fd('-', fd);
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	while (unb)
	{
		buffer[i] = unb % 10;
		unb = unb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar_fd('0' + buffer[i], fd);
		i--;
	}
}
