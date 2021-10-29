/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:34:32 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/11 15:02:14 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc_c;
	unsigned char	*b_tmp;

	uc_c = (unsigned char)c;
	b_tmp = b;
	while (len--)
		*b_tmp++ = uc_c;
	return (b);
}
