/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:50:53 by bson              #+#    #+#             */
/*   Updated: 2022/05/27 19:52:34 by bson             ###   ########.fr       */
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

static double	get_int_idx(const char *str_ptr, int *i)
{
	double		res;
	int			idx;

	idx = *i;
	res = 0.0;
	while (str_ptr[idx] && str_ptr[idx] >= '0' && str_ptr[idx] <= '9')
	{
		res *= 10.0;
		res += str_ptr[idx] - '0';
		++idx;
	}
	*i = idx;
	return (res);
}

static double	get_dec_idx(const char *str_ptr, int *i)
{
	double		res;
	int			idx;
	int			ret_idx;

	idx = *i;
	res = 0.0;
	while (str_ptr[idx] && str_ptr[idx] >= '0' && str_ptr[idx] <= '9')
		++idx;
	ret_idx = idx;
	--idx;
	while (idx != *i)
	{
		res /= 10.0;
		res += str_ptr[idx] - '0';
		--idx;
	}
	res /= 10.0;
	res += str_ptr[idx] - '0';
	res /= 10.0;
	*i = ret_idx;
	return (res);
}

int	check_digit_fail_logic(int c, int *i)
{
	if (ft_isdigit(c))
		return (1);
	*i = -1;
	return (0);
}

double	ft_atof_idx(const char *str, int *i)
{
	double	res;
	int		sign;

	sign = 1;
	res = 0.0;
	while (str[*i] && ft_isspace(str[*i]))
		++(*i);
	if (str[*i] == '-')
	{
		sign = sign * -1;
		++(*i);
	}
	else if (str[*i] == '+')
		++(*i);
	if (!check_digit_fail_logic(str[*i], i))
		return (-666);
	res = get_int_idx(str, i);
	if (str[*i] == '\0' || str[*i] != '.')
		return (res * sign);
	++(*i);
	if (!check_digit_fail_logic(str[*i], i))
		return (-666);
	res += get_dec_idx(str, i);
	return (res * sign);
}
