/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 01:13:53 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/12 13:46:13 by sangjeon         ###   ########.fr       */
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

size_t			ft_strlcat(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	size_t			len_dst;
	size_t			len_src;
	size_t			idx;

	if (!dst || !src)
		return (0);
	len_dst = in_strlen(dst);
	len_src = in_strlen(src);
	if (dstsize == 0 || len_dst > dstsize)
		return (dstsize + len_src);
	while (*dst)
		dst++;
	idx = 0;
	while (idx + len_dst + 1 < dstsize && *src)
	{
		*dst++ = *src++;
		idx++;
	}
	*dst = '\0';
	return (len_dst + len_src);
}
