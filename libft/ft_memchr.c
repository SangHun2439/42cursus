/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:59:36 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 18:55:25 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_tmp;
	unsigned char		uc_c;

	s_tmp = s;
	uc_c = (unsigned char)c;
	while (n--)
	{
		if (*s_tmp == uc_c)
			return ((void *)s_tmp);
		s_tmp++;
	}
	return (0);
}
