/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:02:35 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/11 17:32:12 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	get_conf(const char **p_format, t_conf *p_conf)
{
	get_flag(p_format, p_conf);
	get_width(p_format, p_conf);
	get_prec(p_format, p_conf);
	get_spec(p_format, p_conf);
}

int	intersection(va_list *p_arg, t_conf *p_conf)
{
	if (p_conf->flag & LEFT)
		p_conf->flag &= ~ZEROPAD;
	if (p_conf->spec == 'c')
		return (c_printf(p_arg, p_conf));
	else if (p_conf->spec == 's')
		return (s_printf(p_arg, p_conf));
	else if (ft_strchr("diuxXp", p_conf->spec))
		return (int_printf(p_arg, p_conf));
	else if (p_conf->spec == '%')
		return (per_printf(p_conf));
	return (-1);
}

void	init_conf(t_conf *p_conf)
{
	p_conf->flag = 0;
	p_conf->width = -1;
	p_conf->prec = -1;
	p_conf->spec = 0;
}

int	do_printf(va_list *p_arg, const char *format)
{
	int		res;
	int		arg_len;
	t_conf	conf;

	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			init_conf(&conf);
			format++;
			get_conf(&format, &conf);
			arg_len = intersection(p_arg, &conf);
			if (arg_len < 0)
				return (arg_len);
			res += arg_len;
		}
		else
		{
			ft_putchar_fd(*format++, FD);
			res++;
		}
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		res;

	va_start(arg, format);
	res = do_printf(&arg, format);
	va_end(arg);
	return (res);
}
