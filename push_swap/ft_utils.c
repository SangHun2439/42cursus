/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:03:12 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 17:29:54 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	error(int *err)
{
	*err = 1;
	return (0);
}

int	errcheck_atoi(const char *str, int *err)
{
	int			sign;
	long long	res;

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
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (error(err));
	}
	if (*str)
		return (error(err));
	return (res * sign);
}

void	del(void *content)
{
	free(content);
}
