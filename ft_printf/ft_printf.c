/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:34:02 by sangjeon          #+#    #+#             */
/*   Updated: 2021/06/10 18:45:57 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_conf(const char **p_format, t_conf *p_conf, va_list *p_arg)
{
	get_flag(p_format, p_conf);
	get_width(p_format, p_conf, p_arg);
	get_prec(p_format, p_conf, p_arg);
	get_length(p_format, p_conf);
	get_spec(p_format, p_conf);
}

void	intersection(va_list *p_arg, t_conf *p_conf, int *res)
{
	int		(*f_arr[128])(va_list *, t_conf *);

	if (!(p_conf->spec))
	{
		*res = -1;
		return ;
	}
	if (p_conf->flag & LEFT)
		p_conf->flag &= ~ZEROPAD;
	f_arr['c'] = &c_printf;
	f_arr['s'] = &s_printf;
	f_arr['p'] = &p_printf;
	f_arr['d'] = &d_printf;
	f_arr['i'] = &i_printf;
	f_arr['u'] = &u_printf;
	f_arr['x'] = &x_printf;
	f_arr['X'] = &cx_printf;
	f_arr['%'] = &per_printf;
	f_arr['n'] = &n_printf;
	f_arr['f'] = &f_printf;
	f_arr['g'] = &g_printf;
	f_arr['e'] = &e_printf;
	*res = f_arr[(int)p_conf->spec](p_arg, p_conf);
}

int		do_printf(va_list *p_arg, const char *format)
{
	int		res;
	t_conf	conf;

	conf.flag = 0;
	conf.width = -1;
	conf.prec = -1;
	conf.length = 0;
	conf.spec = 0;
	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			get_conf(&format, &conf, p_arg);
			printf("flag : %d\n", conf.flag);
			printf("width : %d\n", conf.width);
			printf("prec : %d\n", conf.prec);
			printf("length : %d\n", conf.length);
			printf("spec : %c\n", conf.spec);
			intersection(p_arg, &conf, &res);
			if (res < 0)
				return (res);
		}
		else
		{
			ft_putchar_fd(*format++, FD);
			res++;
		}
	}
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		res;

	va_start(arg, format);
	res = do_printf(&arg, format);
	va_end(arg);
	return (res);
}
