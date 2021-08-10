/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:32:56 by sangjeon          #+#    #+#             */
/*   Updated: 2021/06/25 23:34:17 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					c_printf(va_list *p_arg, t_conf *p_conf)
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

int					wc_printf(va_list *p_arg, t_conf *p_conf)
{
	int					size;
	int					arg_val;

	size = 0;
	arg_val = va_arg(*p_arg, wint_t);
	if ((p_conf->arg_len = ft_wclen(arg_val)) == -1)
		return (-1);
	if (!(p_conf->flag & LEFT))
		pad_printf(p_conf, &size);
	ft_putwchar_fd(arg_val, FD);
	size += p_conf->arg_len;
	pad_printf(p_conf, &size);
	return (size);
}

int					s_printf(va_list *p_arg, t_conf *p_conf)
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

int					ws_printf(va_list *p_arg, t_conf *p_conf)
{
	int					size;
	int					idx;
	wchar_t				*arg_val;

	arg_val = va_arg(*p_arg, wchar_t *);
	if (!arg_val)
		arg_val = L"(null)";
	p_conf->arg_len = ft_wstrnlen(arg_val, p_conf->prec);
	idx = p_conf->arg_len;
	size = 0;
	if (!(p_conf->flag & LEFT))
		pad_printf(p_conf, &size);
	while (idx)
	{
		ft_putwchar_fd(*arg_val, FD);
		idx -= ft_wclen(*arg_val);
		arg_val++;
	}
	size += p_conf->arg_len;
	pad_printf(p_conf, &size);
	return (size);
}

int		per_printf(t_conf *p_conf)
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
