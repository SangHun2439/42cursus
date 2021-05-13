/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:43:11 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/12 11:03:07 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	in_strlen(const char *str)
{
	size_t			len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char			*ft_strdup(const char *s1)
{
	char			*res;
	size_t			len;
	size_t			i;

	len = in_strlen(s1);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s1[i] && i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
