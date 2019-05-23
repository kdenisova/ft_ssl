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
	int			len;
	int			bitlen;
}				t_fmd5;

void			md5_init(t_fmd5 *fmd, char *str);
unsigned char 	*md5_update(t_fmd5 *fmd, char *str);
unsigned		rotate(unsigned a, unsigned b);
void			stage_one(t_fmd5 *fmd, unsigned *x);
void			stage_two(t_fmd5 *fmd, unsigned *x);
void			stage_three(t_fmd5 *fmd, unsigned *x);
void			stage_four(t_fmd5 *fmd, unsigned *x);
unsigned		*md5_final(t_fmd5 *fmd);
void			print_md5(unsigned hash[]);//temp

#endif
