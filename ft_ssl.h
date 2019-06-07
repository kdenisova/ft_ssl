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
# include <errno.h>
# include "ft_printf/ft_printf.h"
# define BLOCK_SIZE 64

typedef struct	s_flg
{
	int			p;
	int			q;
	int			r;
	int			s;
	int			i;
	int			fd;
	char		*fdname;
	char		*alg;
}				t_flg;

typedef struct	s_alp
{
	unsigned long	a;
	unsigned long	b;
	unsigned long	c;
	unsigned long	d;
	unsigned long	e;
	unsigned long	f;
	unsigned long	g;
	unsigned long	h;
}				t_alp;

typedef struct	s_fmd5
{
	unsigned	hash[8];
	int			len;
	int			bitlen;
}				t_fmd5;

typedef struct		s_fsha
{
	unsigned long	hash[8];
	unsigned		s[2];
	unsigned		ch;
	unsigned		maj;
	unsigned		tmp1;
	unsigned		tmp2;
	int				len;
	int				bitlen;
	int				round;
}					t_fsha;

int				parse_file(t_flg *flg, t_alp *al, char *arg);
void			flag_init(t_flg *flg, char *arg);
void			parse_flag(t_flg *flg, char *arg);
void			parse_alg(t_flg *flg, char *arg);
void			alphabet_init(t_alp *al);
void			ft_md5(t_flg *flg, t_alp *al, char *arg, int len);
void			ft_sha(t_flg *flg, t_alp *al, char *arg, int len);
unsigned		fun_f(unsigned x, unsigned y, unsigned z);
unsigned		fun_g(unsigned x, unsigned y, unsigned z);
unsigned		fun_h(unsigned x, unsigned y, unsigned z);
unsigned		fun_i(unsigned x, unsigned y, unsigned z);
void			md5_init(t_fmd5 *fmd, char *str, int len);
unsigned		*md5_update(t_fmd5 *fmd, unsigned *x);
char			*get_block_md5(t_fmd5 *fmd, t_alp *al, char *arg);
unsigned		rl(unsigned x, unsigned n);
unsigned		rotr(unsigned x, unsigned n);
unsigned		revers_data(unsigned b);
void			stage_one(t_fmd5 *fmd, t_alp *a, unsigned *x);
void			stage_two(t_fmd5 *fmd, t_alp *a, unsigned *x);
void			stage_three(t_fmd5 *fmd, t_alp *a, unsigned *x);
void			stage_four(t_fmd5 *fmd, t_alp *a, unsigned *x);
unsigned		*md5_final(t_fmd5 *fmd);
void			put_md5(t_flg *flg, t_fmd5 *fmd, char *arg);
void			put_hash(unsigned *hash);
void			sha_init(t_fsha *fsh, t_flg *flg);
unsigned		*sha_update(t_fsha *fsh, unsigned int *w);
void			sha_stages(t_fsha *fsh, t_alp *al, unsigned *w);
void			sha_rounds(t_fsha *fsh, t_alp *al, unsigned *w);
void			sha512_rounds(t_fsha *fsh, t_alp *al, unsigned *w);
void			ft_sha256(t_fsha *fsh, t_alp *al, char *arg);
void			ft_sha512(t_fsha *fsh, t_alp *al, char *arg);
void			put_sha(t_flg *flg, t_fsha *fsh, char *arg);
void			put_hash_sha(t_flg *flg, t_fsha *fsh);

#endif
