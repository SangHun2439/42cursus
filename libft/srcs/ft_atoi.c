/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:40:20 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/13 12:30:45 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char chr)
{
	if (chr == '\t')
		return (1);
	if (chr == '\n')
		return (1);
	if (chr == '\v')
		return (1);
	if (chr == '\f')
		return (1);
	if (chr == '\r')
		return (1);
	if (chr == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int			sign;
	int			res;

	sign = 1;
	res = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	res *= sign;
	return (res);
}
