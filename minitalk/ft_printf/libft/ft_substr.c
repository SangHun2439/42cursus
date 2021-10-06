/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:43:41 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 19:00:20 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	res_len;
	char	*dup;
	char	*res;

	if (!s)
		return (0);
	while (start-- && *s)
		s++;
	res_len = ft_strlen(s);
	if (res_len > len)
		res_len = len;
	res = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (0);
	dup = res;
	while (res_len--)
		*dup++ = *s++;
	*dup = '\0';
	return (res);
}
