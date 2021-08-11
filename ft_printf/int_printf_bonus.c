/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:04:45 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/11 17:04:51 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	sign_deal(t_conf *p_conf, int *size, long long nbr)
{
	if (p_conf->flag & SIGN)
	{
		if (nbr < 0)
			count_putchar_fd('-', FD, size);
		else if (p_conf->flag & PLUS)
			count_putchar_fd('+', FD, size);
		else if (p_conf->flag & SPACE)
			count_putchar_fd(' ', FD, size);
	}
}

void	nbr_deal(unsigned long long u_nbr, char *base, \
		unsigned int baselen, int *size)
{
	if (u_nbr < baselen)
	{
		count_putchar_fd(base[u_nbr], FD, size);
		return ;
	}
	nbr_deal(u_nbr / baselen, base, baselen, size);
	nbr_deal(u_nbr % baselen, base, baselen, size);
}

void	count_putnbr_base(long long nbr, \
		char *base, t_conf *p_conf, int *size)
{
	unsigned int		baselen;
	unsigned long long	u_nbr;
	int					digits;

	digits = 0;
	baselen = (unsigned int)ft_strlen(base);
	u_nbr = nbr;
	if ((p_conf->flag & SIGN) && nbr < 0)
		u_nbr = -nbr;
	sign_deal(p_conf, size, nbr);
	special_printf(p_conf, size);
	while ((p_conf->prec)-- > 0)
		count_putchar_fd('0', FD, size);
	nbr_deal(u_nbr, base, baselen, size);
}

int	int_printf(va_list *p_arg, t_conf *p_conf)
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
		if (!(p_conf->flag & LEFT) && (p_conf->flag & SPECIAL) \
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
