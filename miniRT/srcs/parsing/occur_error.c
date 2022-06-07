/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occur_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:51:33 by bson              #+#    #+#             */
/*   Updated: 2022/05/27 19:06:36 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_error(char *error_detail)
{
	ft_assert(FALSE, error_detail);
}

void	*ft_calloc_assert(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(size * count);
	ft_assert(temp != (void *)0, "Out of memory in ft_calloc()");
	ft_bzero(temp, (size * count));
	return (temp);
}
