/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:54:24 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/15 18:33:58 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (*s)
	{
		res[i] = f(i, *s);
		s++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
