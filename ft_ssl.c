/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:06:47 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/20 11:06:50 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"





int				main(void)
{
	t_fmd5 fmd;
	char *str = "hello1234567890asashdadl";
	unsigned *x;

	md5_init(&fmd, str);
	x = (unsigned *)ft_strnew(16);
	x = (unsigned *)md5_update(&fmd, str);
	x[15] = 0;
	stage_one(&fmd, x);
	printf("MD5 (""%s"") = ", str);
	print_md5(md5_final(&fmd));
	printf("\n");
	return (0);
}
