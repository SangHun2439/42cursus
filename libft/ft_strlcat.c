/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 01:13:53 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/15 16:53:02 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	size_t			idx;

	idx = 0;
	while (dst[idx] && idx + 1 < dstsize)
		idx++;
	if (dst[idx])
		return (dstsize + ft_strlen(src));
	while (*src && idx + 1 < dstsize)
		dst[idx++] = *src++;
	dst[idx] = '\0';
	while (*src)
	{
		src++;
		idx++;
	}
	return (idx);
}
