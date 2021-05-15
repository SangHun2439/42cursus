/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:03:31 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/14 17:22:07 by sangjeon         ###   ########.fr       */
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

char		*ft_itoa(int n)
{
	int			minus;
	int			num;
	char		*res;
	size_t		res_len;

	minus = 0;
	if (n < 0)
		minus = 1;
	res_len = digit_len(n) + minus;
	if (!(res = (char *)malloc(sizeof(char) * (res_len + 1))))
		return (0);
	res[res_len] = '\0';
	if (n == 0)
		*res = '0';
	while (n != 0)
	{
		num = minus ? -(n % 10) : (n % 10);
		n = n / 10;
		res[res_len - 1] = num + '0';
		res_len--;
	}
	if (minus)
		*res = '-';
	return (res);
}
