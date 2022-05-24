/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:20:34 by sangjeon          #+#    #+#             */
/*   Updated: 2022/05/18 17:46:44 by sangjeon         ###   ########.fr       */
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

double	get_int(const char **str_ptr)
{
	double		res;
	const char	*str;

	res = 0.0;
	str = *str_ptr;
	while (*str && *str >= '0' && *str <= '9')
	{
		res *= 10.0;
		res += *str - '0';
		str++;
	}
	*str_ptr = str;
	return (res);
}

double	get_dec(const char **str_ptr)
{
	double		res;
	const char	*str;

	res = 0.0;
	str = *str_ptr;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	str--;
	while (str != *str_ptr)
	{
		res /= 10.0;
		res += *str - '0';
		str--;
	}
	res /= 10.0;
	res += *str - '0';
	res /= 10.0;
	return (res);
}

double	ft_atof(const char *str)
{
	double	res;
	int		sign;

	sign = 1;
	res = 0.0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = get_int(&str);
	if (!(*str))
		return (res * sign);
	str++;
	res += get_dec(&str);
	return (res * sign);
}
