/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:02:53 by sangjeon          #+#    #+#             */
/*   Updated: 2021/06/10 18:47:31 by sangjeon         ###   ########.fr       */
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

void	get_width(const char **p_format, t_conf *p_conf, va_list *p_arg)
{
	if (**p_format == '*')
	{
		*p_format = *p_format + 1;
		p_conf->width = va_arg(*p_arg, int);
		if (p_conf->width < 0)
		{
			p_conf->width *= -1;
			p_conf->flag |= LEFT;
		}
	}
	else if (ft_isdigit(**p_format))
		p_conf->width = addr_mov_atoi(p_format);
}

void	get_prec(const char **p_format, t_conf *p_conf, va_list *p_arg)
{
	if (**p_format == '.')
	{
		*p_format = *p_format + 1;
		if (**p_format == '*')
		{
			*p_format = *p_format + 1;
			p_conf->prec = va_arg(*p_arg, int);
			if (p_conf->prec < 0)
				p_conf->prec = -1;
		}
		else if (ft_isdigit(**p_format))
			p_conf->prec = addr_mov_atoi(p_format);
	}
}

void	get_length(const char **p_format, t_conf *p_conf)
{
	if (!ft_strncmp(*p_format, "hh", 2))
	{
		p_conf->length |= HH;
		*p_format = *p_format + 2;
	}
	else if (!ft_strncmp(*p_format, "h", 1))
	{
		p_conf->length |= H;
		*p_format = *p_format + 1;
	}
	else if (!ft_strncmp(*p_format, "ll", 2))
	{
		p_conf->length |= LL;
		*p_format = *p_format + 2;
	}
	else if (!ft_strncmp(*p_format, "l", 1))
	{
		p_conf->length |= L;
		*p_format = *p_format + 1;
	}
}

void	get_spec(const char **p_format, t_conf *p_conf)
{
	if (ft_strchr("cspdiuxX%nfge", **p_format))
	{
		p_conf->spec = **p_format;
		*p_format = *p_format + 1;
	}
}
