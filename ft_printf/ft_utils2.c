/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:07:28 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 20:42:49 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_intlen(long long nbr, char *base, t_conf *p_conf)
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
	u_nbr /= len;
	while (u_nbr != 0)
	{
		int_len++;
		u_nbr /= len;
	}
	p_conf->prec -= int_len;
	if (p_conf->prec > 0)
		int_len = p_conf->prec + int_len;
	special_len(p_conf, &int_len);
	return (int_len);
}

void	set_intarg(va_list *p_arg, t_conf *p_conf,
		long long *p_arg_val, char **p_base)
{
	if (p_conf->spec == 'p')
	{
		*p_arg_val = (long long)va_arg(*p_arg, void *);
		p_conf->flag |= SPECIAL;
	}
	else
		*p_arg_val = va_arg(*p_arg, int);
	if (p_conf->spec == 'x' || p_conf->spec == 'p')
		*p_base = "0123456789abcdef";
	if (p_conf->spec == 'X')
		*p_base = "0123456789ABCDEF";
	if (p_conf->spec == 'd' || p_conf->spec == 'i' || p_conf->spec == 'u')
		*p_base = "0123456789";
}
