/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:14:24 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 18:43:06 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d_tmp;
	const char	*s_tmp;

	if (!dst && !src)
		return (dst);
	s_tmp = src;
	d_tmp = dst;
	while (n--)
		*d_tmp++ = *s_tmp++;
	return (dst);
}
