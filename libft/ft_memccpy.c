/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:10:01 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 18:43:28 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d_tmp;
	const unsigned char	*s_tmp;
	unsigned char		uc_c;

	uc_c = (unsigned char)c;
	s_tmp = src;
	d_tmp = dst;
	while (n--)
	{
		if (*s_tmp == uc_c)
		{
			*d_tmp++ = *s_tmp++;
			return ((void *)d_tmp);
		}
		*d_tmp++ = *s_tmp++;
	}
	return (0);
}
