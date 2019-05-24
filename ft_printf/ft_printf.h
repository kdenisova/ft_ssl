/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:18:53 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/01 11:19:46 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# define MD_H   1
# define MD_HH  2
# define MD_L   3
# define MD_LL  4
# define MD_BL	5
# define NZ		-0.0

int				ft_printf(const char *format, ...);
int				parse_format(va_list *list, const char **format);
void			put_zero(int zero);

typedef struct	s_flag
{
	int			md;
	int			len;
	int			base;
	int			space;
	int			plus;
	int			minus;
	int			zero;
	int			hash;
	int			width;
	int			prec;
	int			neg;
	int			sign;
}				t_flag;

void			fill_list(t_flag *flg, const char **format);
int				parse_md(t_flag *flg, const char **format);
int				parse_width(const char **format);
int				parse_convert(t_flag *flg, const char **format);
int				arg_unint(va_list *list, t_flag *flg, const char **format);
int				arg_int(va_list *list, t_flag *flg);
int				format_string(t_flag *flg);
int				format_float(va_list *list, t_flag *flg);
int				format_int(t_flag *flg, int ret, int flag);
int				format_unint(t_flag *flg, int ret, unsigned long long int n);
int				check_nan(t_flag *flg, int ret);
int				check_inf(t_flag *flg, double i, int ret);
int				check_negzero(t_flag *flg);
int				prep_float(t_flag *flg, long long int nbr, int ret);
int				prep_unint(t_flag *flg, const char **format, void *nbr);
int				print_nbr(t_flag *flg, unsigned long long int n, int ret);
int				get_posprec(t_flag *flg, int ret);
int				get_string(va_list *list, t_flag *flg);
int				get_unint(t_flag *flg, const char **format, void *nbr);
int				get_negative(t_flag *flg, unsigned long long int n);
int				get_negprec(t_flag *flg, int ret);
int				get_nbr(t_flag *flg, void *nbr, int ret);
void			get_lnint(t_flag *flg, unsigned long long int	n);
int				get_altr(t_flag *flg, const char **format, \
				unsigned long long int nbr);
long long int	get_precfl(int pr);
int				get_lnfloat(double n, int pr);
void			put_space(t_flag *flg);
int				put_posfield(t_flag *flg, unsigned long long int n, int ret);
int				put_negfield(t_flag *flg, unsigned long long int n, int ret);
void			put_int(long nbr);
void			put_sign(t_flag *flg);
int				put_plus(t_flag *flg, int ret);
void			put_nbr(t_flag *flg, unsigned long long int n);
void			put_altr(const char **format);
int				put_altpos(t_flag *flg, const char **format, int ret);
void			put_width(t_flag *flg);
int				put_char(va_list *list, t_flag *flg);
int				put_string(t_flag *flg, char *s);
int				put_inf(t_flag *flg, int ret, double i);
void			put_posfloat(t_flag *flg, double i, int flag, int prec);
void			put_negfloat(t_flag *flg, double i, int prec);
void			put_float(t_flag *flg, double i, long long int nbr, int prec);
void			put_unint(t_flag *flg, const char **format, \
				unsigned long long int	n);
int				put_zunint(t_flag *flg, unsigned long long int n, int ret);
void			put_unsigned(unsigned long long int n, int base);

#endif
