/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:44:17 by sangjeon          #+#    #+#             */
/*   Updated: 2021/06/12 17:48:57 by sangjeon         ###   ########.fr       */
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
}				t_conf;

int				ft_printf(const char *format, ...);
void			get_flag(const char **p_format, t_conf *p_conf);
void			get_width(const char **p_format,
		t_conf *p_conf, va_list *p_arg);
void			get_prec(const char **p_format,
		t_conf *p_conf, va_list *p_arg);
void			get_length(const char **p_format, t_conf *p_conf);
void			get_spec(const char **p_format, t_conf *p_conf);
int				addr_mov_atoi(const char **s);
int				c_printf(va_list *p_arg, t_conf *p_conf);
int				s_printf(va_list *p_arg, t_conf *p_conf);
int				p_printf(va_list *p_arg, t_conf *p_conf);
int				d_printf(va_list *p_arg, t_conf *p_conf);
int				i_printf(va_list *p_arg, t_conf *p_conf);
int				u_printf(va_list *p_arg, t_conf *p_conf);
int				x_printf(va_list *p_arg, t_conf *p_conf);
int				cx_printf(va_list *p_arg, t_conf *p_conf);
int				per_printf(va_list *p_arg, t_conf *p_conf);
int				n_printf(va_list *p_arg, t_conf *p_conf);
int				f_printf(va_list *p_arg, t_conf *p_conf);
int				g_printf(va_list *p_arg, t_conf *p_conf);
int				e_printf(va_list *p_arg, t_conf *p_conf);
int				ft_strnlen(const char *str, int n);
void			count_putchar_fd(char c, int fd, int *size);
void			ft_putwchar_fd(int wc, int fd);

#endif
