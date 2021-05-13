/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:35:24 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/11 17:34:20 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d_tmp;
	const char	*s_tmp;

	if (!dst && !src)
		return (dst);
	d_tmp = dst;
	s_tmp = src;
	if (src >= dst)
	{
		while (len--)
			*d_tmp++ = *s_tmp++;
	}
	else
	{
		d_tmp += len;
		s_tmp += len;
		while (len--)
			*--d_tmp = *--s_tmp;
	}
	return (dst);
}
