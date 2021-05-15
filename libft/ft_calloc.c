/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:08:03 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/12 11:17:14 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	in_bzero(void *s, size_t n)
{
	char		*chr_s;

	chr_s = (char *)s;
	while (n--)
		*chr_s++ = 0;
}

void		*ft_calloc(size_t count, size_t size)
{
	void		*res;

	if (!(res = malloc(count * size)))
		return (0);
	in_bzero(res, count * size);
	return (res);
}
