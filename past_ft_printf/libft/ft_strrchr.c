/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:40:09 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/15 18:43:10 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr_c;
	char	*res;

	res = 0;
	chr_c = (char)c;
	while (*s)
	{
		if (*s == chr_c)
			res = (char *)s;
		s++;
	}
	if (!chr_c)
		res = (char *)s;
	return (res);
}
