/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:44:17 by sangjeon          #+#    #+#             */
/*   Updated: 2021/10/04 16:14:54 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define FD 1

# define ZEROPAD 1
# define SPACE 2
# define PLUS 4
# define LEFT 8
# define SPECIAL 16
# define SIGN 32

typedef struct s_conf
{
	int				flag;
	int				width;
	int				prec;
	char			spec;
	int				arg_len;
}	t_conf;

int				ft_printf(const char *format, ...);
char			*ft_strchr(const char *s, int c);
void			ft_putchar_fd(char c, int fd);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
int				ft_printf(const char *format, ...);
void			get_flag(const char **p_format, t_conf *p_conf);
void			get_width(const char **p_format, t_conf *p_conf);
void			get_prec(const char **p_format,	t_conf *p_conf);
void			get_spec(const char **p_format, t_conf *p_conf);
int				addr_mov_atoi(const char **s);
int				c_printf(va_list *p_arg, t_conf *p_conf);
int				s_printf(va_list *p_arg, t_conf *p_conf);
int				int_printf(va_list *p_arg, t_conf *p_conf);
int				per_printf(t_conf *p_conf);
int				ft_strnlen(const char *str, int n);
void			count_putchar_fd(char c, int fd, int *size);
void			count_putnbr_base(long long nbr, \
		char *base, t_conf *p_conf, int *size);
void			pad_printf(t_conf *p_conf, int *size);
void			special_printf(t_conf *p_conf, int *size);
int				ft_intlen(long long nbr, char *base, t_conf *p_conf);
void			set_intarg(va_list *p_arg, t_conf *p_conf, \
		long long *p_arg_val, char **p_base);

#endif
