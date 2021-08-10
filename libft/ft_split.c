/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:54:18 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 18:54:51 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issep(const char cha, const char c)
{
	if (cha == c)
		return (1);
	return (0);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t			counts;

	counts = 0;
	while (*s)
	{
		if (!ft_issep(*s, c))
		{
			counts++;
			while (*s && !ft_issep(*s, c))
				s++;
		}
		else
			s++;
	}
	return (counts);
}

static char	*ft_str_cpy(char const *str, size_t len)
{
	char			*res;
	size_t			i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

static int	ft_do_split(char **res, char const *s, char c,
		size_t word_nmb)
{
	size_t			i;
	size_t			word_len;
	char const		*tmp;

	i = 0;
	while (*s && i < word_nmb)
	{
		if (!ft_issep(*s, c))
		{
			word_len = 0;
			tmp = s;
			while (*s && !ft_issep(*s++, c))
				word_len++;
			res[i] = ft_str_cpy(tmp, word_len);
			if (!res[i])
				return (0);
			i++;
		}
		else
			s++;
	}
	res[word_nmb] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t			word_nmb;
	char			**res;
	int				i;

	if (!s)
		return (0);
	word_nmb = ft_word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (word_nmb + 1));
	if (!res)
		return (0);
	if (!ft_do_split(res, s, c, word_nmb))
	{
		i = 0;
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (0);
	}
	return (res);
}
