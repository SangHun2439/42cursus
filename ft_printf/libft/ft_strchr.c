/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:46:25 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/12 13:44:57 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch_c;

	ch_c = (char)c;
	while (*s)
	{
		if (*s == ch_c)
			return ((char *)s);
		s++;
	}
	if (!ch_c)
		return ((char *)s);
	return (0);
}
