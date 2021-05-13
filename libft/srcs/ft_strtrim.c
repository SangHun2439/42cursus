/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:14:47 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/12 23:44:26 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	in_trimlen(char const *s1, char const *set)
{
	size_t			res;
	size_t			set_len;

	res = 0;
	set_len = ft_strlen(set);
	while (*s1)
	{
		if (!ft_strncmp(s1, set, set_len))
			s1 += set_len;
		else
		{
			s1++;
			res++;
		}
	}
	return (res);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	char			*dup;
	size_t			res_len;
	size_t			set_len;

	set_len = ft_strlen(set);
	res_len = in_trimlen(s1, set);
	if (!(res = (char *)malloc(sizeof(char) * (res_len + 1))))
		return (0);
	dup = res;
	while (*s1)
	{
		if (!ft_strncmp(s1, set, set_len))
			s1 += set_len;
		else
			*dup++ = *s1++;
	}
	*dup = '\0';
	return (res);
}
