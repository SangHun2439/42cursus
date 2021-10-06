/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 07:31:48 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 20:45:58 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strnlen(char const *str, int n)
{
	int		res;

	res = 0;
	while (*str++ && n--)
		res++;
	return (res);
}

void	count_putchar_fd(char c, int fd, int *size)
{
	write(fd, &c, 1);
	*size = *size + 1;
}

int	addr_mov_atoi(const char **s)
{
	int		res;

	res = 0;
	while (ft_isdigit(**s))
	{
		res *= 10;
		res += **s - '0';
		*s = *s + 1;
	}
	return (res);
}

void	special_printf(t_conf *p_conf, int *size)
{
	if (p_conf->flag & SPECIAL)
	{
		if (p_conf->spec == 'p' || p_conf->spec == 'x')
		{
			count_putchar_fd('0', FD, size);
			count_putchar_fd('x', FD, size);
		}
		if (p_conf->spec == 'X')
		{
			count_putchar_fd('0', FD, size);
			count_putchar_fd('X', FD, size);
		}
	}
}

void	pad_printf(t_conf *p_conf, int *size)
{
	char	pad;

	pad = ' ';
	if (p_conf->flag & ZEROPAD)
		pad = '0';
	while (p_conf->width > p_conf->arg_len)
	{
		count_putchar_fd(pad, FD, size);
		p_conf->width--;
	}
}
