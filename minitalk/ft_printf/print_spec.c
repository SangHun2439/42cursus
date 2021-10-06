/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:32:56 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 20:38:48 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_printf(va_list *p_arg, t_conf *p_conf)
{
	int					size;

	p_conf->arg_len = 1;
	size = 0;
	if (!(p_conf->flag & LEFT))
		pad_printf(p_conf, &size);
	count_putchar_fd((unsigned char)va_arg(*p_arg, int), FD, &size);
	pad_printf(p_conf, &size);
	return (size);
}

int	s_printf(va_list *p_arg, t_conf *p_conf)
{
	int					size;
	int					idx;
	char				*arg_val;

	arg_val = va_arg(*p_arg, char *);
	if (!arg_val)
		arg_val = "(null)";
	p_conf->arg_len = ft_strnlen(arg_val, p_conf->prec);
	idx = p_conf->arg_len;
	size = 0;
	if (!(p_conf->flag & LEFT))
		pad_printf(p_conf, &size);
	while (idx--)
		count_putchar_fd(*arg_val++, FD, &size);
	pad_printf(p_conf, &size);
	return (size);
}

int	per_printf(t_conf *p_conf)
{
	int		size;

	size = 0;
	p_conf->arg_len = 1;
	if (!(p_conf->flag & LEFT))
		pad_printf(p_conf, &size);
	count_putchar_fd('%', FD, &size);
	pad_printf(p_conf, &size);
	return (size);
}
