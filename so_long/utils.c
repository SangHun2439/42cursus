/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:10:46 by sangjeon          #+#    #+#             */
/*   Updated: 2021/11/01 17:05:31 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	split_free(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int		count_digit(int a)
{
	int	res;

	if (a == 0)
		return (1);
	res = 0;
	while (a != 0)
	{
		res++;
		a = a / 10;
	}
	return (res);
}

char	*simple_itoa(int a)
{
	char	*res;
	int		digit;

	digit = count_digit(a);
	res = (char *)malloc(sizeof(char) * (digit + 1));
	res[digit--] = '\0';
	while (digit >= 0)
	{
		res[digit--] = a % 10 + '0';
		a = a / 10;
	}
	return (res);
}
