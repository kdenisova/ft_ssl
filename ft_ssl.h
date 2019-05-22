/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:07:48 by kdenisov          #+#    #+#             */
/*   Updated: 2019/05/20 11:08:08 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdio.h> //DELETE
# include "libft/libft.h"

unsigned		fun_f(unsigned x, unsigned y, unsigned z);
unsigned		fun_g(unsigned x, unsigned y, unsigned z);
unsigned		fun_h(unsigned x, unsigned y, unsigned z);
unsigned		fun_i(unsigned x, unsigned y, unsigned z);

typedef struct	s_fmd5
{
	unsigned	hash[8];
	unsigned	bits[2];
	int			len;
	int			bitlen;
}   			t_fmd5;

void			stage_one(t_fmd5 *fmd, unsigned *x);
void			stage_two(t_fmd5 *fmd, unsigned *x);
void			stage_three(t_fmd5 *fmd, unsigned *x);
void			stage_four(t_fmd5 *fmd, unsigned *x);

#endif
