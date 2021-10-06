/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:02:53 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/11 16:00:53 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(const char **p_format, t_conf *p_conf)
{
	while (**p_format && ft_strchr("-+ #0", **p_format))
	{
		if (**p_format == '-')
			p_conf->flag |= LEFT;
		else if (**p_format == '+')
			p_conf->flag |= PLUS;
		else if (**p_format == ' ')
			p_conf->flag |= SPACE;
		else if (**p_format == '#')
			p_conf->flag |= SPECIAL;
		else if (**p_format == '0')
			p_conf->flag |= ZEROPAD;
		*p_format = *p_format + 1;
	}
}

void	get_width(const char **p_format, t_conf *p_conf)
{
	if (ft_isdigit(**p_format))
		p_conf->width = addr_mov_atoi(p_format);
}

void	get_prec(const char **p_format, t_conf *p_conf)
{
	if (**p_format == '.')
	{
		*p_format = *p_format + 1;
		p_conf->prec = addr_mov_atoi(p_format);
	}
}

void	get_spec(const char **p_format, t_conf *p_conf)
{
	if (ft_strchr("cspdiuxX%", **p_format))
	{
		p_conf->spec = **p_format;
		*p_format = *p_format + 1;
		if (p_conf->spec == 'd' || p_conf->spec == 'i')
			p_conf->flag |= SIGN;
	}
}
