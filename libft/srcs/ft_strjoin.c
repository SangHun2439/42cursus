/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:59:02 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/12 14:03:37 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	res_len;
	char	*dup;
	char	*res;

	res_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (res_len + 1))))
		return (0);
	dup = res;
	while (*s1)
		*dup++ = *s1++;
	while (*s2)
		*dup++ = *s2++;
	*dup = '\0';
	return (res);
}
