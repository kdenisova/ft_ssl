/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:56:03 by kdenisov          #+#    #+#             */
/*   Updated: 2019/02/21 14:56:30 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst_str(t_list *lst)
{
	while (lst)
	{
		ft_putstr((char *)lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
}
