/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:14:06 by sangjeon          #+#    #+#             */
/*   Updated: 2021/06/25 22:16:31 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void			nbr_deal(unsigned long long u_nbr, char *base,
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

void			count_putnbr_base(long long nbr,
		char *base, t_conf *p_conf, int *size)
{
	unsigned int		baselen;
	unsigned long long	u_nbr;
	int					arg_len;
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
