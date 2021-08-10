/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:03:31 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 20:11:06 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_len(int n)
{
	int			digit;

	if (n == 0)
		return (1);
	digit = 0;
	while (n != 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	long long	num;
	char		*res;
	size_t		res_len;

	num = n;
	res_len = digit_len(n);
	if (num < 0)
	{
		res_len++;
		num *= -1;
	}
	res = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (0);
	res[res_len--] = '\0';
	if (num == 0)
		res[res_len--] = '0';
	while (num != 0)
	{
		res[res_len--] = (num % 10) + '0';
		num /= 10;
	}
	if (res_len == 0)
		res[res_len] = '-';
	return (res);
}
