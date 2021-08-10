/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:34:43 by sangjeon          #+#    #+#             */
/*   Updated: 2021/07/09 16:19:49 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_printf(va_list *p_arg, t_conf *p_conf)
{
	int			size;
	long long	arg_val;
	char		*base;

	set_intarg(p_arg, p_conf, &arg_val, &base);
	if (!arg_val && !(p_conf->spec == 'p'))
		p_conf->flag &= ~SPECIAL;
	size = 0;
	if (p_conf->flag & ZEROPAD)
	{
		p_conf->flag &= ~ZEROPAD;
		if (!(p_conf->flag & LEFT) && (p_conf->flag & SPECIAL)
				&& (p_conf->prec == -1))
			p_conf->prec = p_conf->width - 2;
		else if (!(p_conf->flag & LEFT) && (p_conf->prec == -1))
			p_conf->prec = p_conf->width;
	}
	p_conf->arg_len = ft_intlen(arg_val, base, p_conf);
	if (!(p_conf->flag & LEFT))
		pad_printf(p_conf, &size);
	count_putnbr_base(arg_val, base, p_conf, &size);
	pad_printf(p_conf, &size);
	return (size);
}

int		dec_printf(va_list *p_arg, t_conf *p_conf)
{
	int		size;
	double	arg_val;

	size = 0;
	if (p_conf->prec == -1)
		p_conf->prec = 6;
	else if (p_conf->prec == 0 && p_conf->spec == 'g')
		p_conf->prec = 1;
	arg_val = va_arg(*p_arg, double);
	do_decprintf(arg_val, &size, p_conf);
	return (size);
}

int		n_printf(va_list *p_arg, t_conf *p_conf, int res)
{
	if (!p_conf->length)
		*(va_arg(*p_arg, int *)) = res;
	else if (p_conf->length & L)
		*(va_arg(*p_arg, long *)) = res;
	else if (p_conf->length & LL)
		*(va_arg(*p_arg, long long *)) = res;
	else if (p_conf->length & H)
		*(va_arg(*p_arg, short *)) = res;
	else if (p_conf->length & HH)
		*(va_arg(*p_arg, char *)) = res;
	return (0);
}
