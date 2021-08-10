/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:22:10 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 18:24:49 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	static_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	static_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0 && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack,
		const char *needle, size_t len)
{
	size_t			str_size;

	if (!*needle)
		return ((char *)haystack);
	str_size = static_strlen(needle);
	while (len && *haystack)
	{
		if (len < str_size)
			break ;
		if (!static_strncmp(haystack, needle, str_size))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
