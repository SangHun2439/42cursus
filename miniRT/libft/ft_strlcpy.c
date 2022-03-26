/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:52:30 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 18:33:54 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	in_strlen(const char *str)
{
	size_t			len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			len;
	size_t			idx;

	if (!dst || !src)
		return (0);
	len = in_strlen(src);
	if (dstsize == 0)
		return (len);
	idx = 0;
	while (*src && idx + 1 < dstsize)
	{
		*dst++ = *src++;
		idx++;
	}
	*dst = '\0';
	return (len);
}
