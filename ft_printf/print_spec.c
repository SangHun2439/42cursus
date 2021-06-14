/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:32:56 by sangjeon          #+#    #+#             */
/*   Updated: 2021/06/10 18:52:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_printf(va_list *p_arg, t_conf *p_conf)
{
	int		size;

	size = 0;
	if (!(p_conf->flag & LEFT))
		while ((p_conf->width)-- > 1)
			count_putchar_fd(' ', FD, &size);
	count_putchar_fd((unsigned char)va_arg(*p_arg, int), FD, &size);
	while ((p_conf->width)-- > 1)
		count_putchar_fd(' ', FD, &size);
	return (size);
}

int		s_printf(va_list *p_arg, t_conf *p_conf)
{
	int		size;
	int		len;
	int		idx;
	char	*arg_val;

	arg_val = va_arg(*p_arg, char *);
	len = ft_strnlen(arg_val, p_conf->prec);
	idx = len;
	size = 0;
	if (!(p_conf->flag & LEFT))
		while ((p_conf->width)-- > len)
			count_putchar_fd(' ', FD, &size);
	while (idx--)
		count_putchar_fd(*arg_val++, FD, &size);
	while ((p_conf->width)-- > len)
		count_putchar_fd(' ', FD, &size);
	return (size);
}

int		p_printf(va_list *p_arg, t_conf *p_conf)
{
	int		res;

	p_arg = 0;
	p_conf = 0;
	res = 0;
	return (res);
}

int		d_printf(va_list *p_arg, t_conf *p_conf)
{
	int		res;

	p_arg = 0;
	p_conf = 0;
	res = 0;
	return (res);
}

int		i_printf(va_list *p_arg, t_conf *p_conf)
{
	int		res;

	p_arg = 0;
	p_conf = 0;
	res = 0;
	return (res);
}
