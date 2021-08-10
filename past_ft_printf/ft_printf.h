/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:44:17 by sangjeon          #+#    #+#             */
/*   Updated: 2021/07/14 11:27:16 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include "libft.h"

# define FD 1

# define ZEROPAD 1
# define SPACE 2
# define PLUS 4
# define LEFT 8
# define SPECIAL 16
# define SIGN 32

# define LL 1
# define L 2
# define HH 4
# define H 8

typedef struct	s_conf
{
	int				flag;
	int				width;
	int				prec;
	int				length;
	char			spec;
	int				arg_len;
}				t_conf;

typedef union	u_dtob
{
	double			val;
	struct
	{
		unsigned long long	frac :52 ;
		unsigned int		expt :11 ;
		unsigned char		sign :1 ;
	}			bit;
}				t_dtob;

int				ft_printf(const char *format, ...);
void			get_flag(const char **p_format, t_conf *p_conf);
void			get_width(const char **p_format,
		t_conf *p_conf, va_list *p_arg);
void			get_prec(const char **p_format,
		t_conf *p_conf, va_list *p_arg);
void			get_length(const char **p_format, t_conf *p_conf);
void			get_spec(const char **p_format, t_conf *p_conf);
int				addr_mov_atoi(const char **s);
int				wc_printf(va_list *p_arg, t_conf *p_conf);
int				c_printf(va_list *p_arg, t_conf *p_conf);
int				ws_printf(va_list *p_arg, t_conf *p_conf);
int				s_printf(va_list *p_arg, t_conf *p_conf);
int				p_printf(va_list *p_arg, t_conf *p_conf);
int				int_printf(va_list *p_arg, t_conf *p_conf);
int				dec_printf(va_list *p_arg, t_conf *p_conf);
int				per_printf(t_conf *p_conf);
int				n_printf(va_list *p_arg, t_conf *p_conf, int res);
int				ft_strnlen(const char *str, int n);
int				ft_wclen(int wc);
int				ft_wstrnlen(wchar_t const *wstr, int n);
void			count_putchar_fd(char c, int fd, int *size);
void			ft_putwchar_fd(int wc, int fd);
void			count_putnbr_base(long long nbr,
		char *base, t_conf *p_conf, int *size);
void			pad_printf(t_conf *p_conf, int *size);
void			special_printf(t_conf *p_conf, int *size);
int				ft_intlen(long long nbr, char *base, t_conf *p_conf);
void			set_intarg(va_list *p_arg, t_conf *p_conf,
		long long *p_arg_val, char **p_base);
int				ft_declen(double dec, t_conf *p_conf);
void			do_decprintf(double arg_val, int *size, t_conf *p_conf);

#endif
