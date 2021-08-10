/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:07:28 by sangjeon          #+#    #+#             */
/*   Updated: 2021/07/09 15:56:39 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wclen(int wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else if (wc <= 0x1FFFFF)
		return (4);
	return (-1);
}

int		ft_wstrnlen(wchar_t const *wstr, int n)
{
	int		res;
	int		len;
	char	defal;

	defal = 0;
	if (n == -1)
		defal = 1;
	res = 0;
	while (*wstr && n)
	{
		len = ft_wclen((int)*wstr);
		if (defal || n >= len)
		{
			res += len;
			n -= len;
			wstr++;
		}
		else
			break;
	}
	return (res);
}

void	special_len(t_conf *p_conf, int *p_res)
{
	char	spec;

	spec = p_conf->spec;
	if (p_conf->flag & SPECIAL)
	{
		if (spec == 'p' || spec == 'x' || spec == 'X')
			*p_res += 2;
	}
}

int		ft_intlen(long long nbr, char *base, t_conf *p_conf)
{
	unsigned long long	u_nbr;
	unsigned int		len;
	int					int_len;

	int_len = 1;
	len = ft_strlen(base);
	u_nbr = nbr;
	if ((p_conf->flag & SIGN) && nbr < 0)
	{
		u_nbr = -nbr;
		int_len++;
	}
	else if ((p_conf->flag & SIGN) && (p_conf->flag & (PLUS + SPACE)))
		int_len++;
	while ((u_nbr /= len) != 0)
		int_len++;
	p_conf->prec -= int_len;
	if (p_conf->prec > 0)
		int_len = p_conf->prec + int_len;
	special_len(p_conf, &int_len);
	return (int_len);
}

void		set_intarg(va_list *p_arg, t_conf *p_conf,
		long long *p_arg_val, char **p_base)
{
	if (p_conf->spec == 'p')
	{
		*p_arg_val = (long long)va_arg(*p_arg, void *);
		p_conf->flag |= SPECIAL;
	}
	else if (!p_conf->length)
		*p_arg_val = va_arg(*p_arg, int);
	else if (p_conf->length & L)
		*p_arg_val = va_arg(*p_arg, long);
	else if (p_conf->length & LL)
		*p_arg_val = va_arg(*p_arg, long long);
	else if (p_conf->length & H)
		*p_arg_val = (short)va_arg(*p_arg, int);
	else if (p_conf->length &HH)
		*p_arg_val = (char)va_arg(*p_arg, int);
	if (p_conf->spec == 'x' || p_conf->spec == 'p')
		*p_base = "0123456789abcdef";
	if (p_conf->spec == 'X')
		*p_base = "0123456789ABCDEF";
	if (p_conf->spec == 'd' || p_conf->spec == 'i' || p_conf->spec == 'u')
		*p_base = "0123456789";
}
