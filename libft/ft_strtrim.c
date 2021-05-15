/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:14:47 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/15 13:32:40 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	char		*dup;
	char const	*end;
	size_t		res_len;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1) != 0 ? s1 + ft_strlen(s1) - 1 : s1;
	res_len = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (end > s1 && ft_strchr(set, *end))
		end--;
	while (*s1 && s1 + res_len <= end)
		res_len++;
	if (!(res = (char *)malloc(sizeof(char) * (res_len + 1))))
		return (0);
	dup = res;
	while (*s1 && s1 <= end)
		*dup++ = *s1++;
	*dup = '\0';
	return (res);
}
