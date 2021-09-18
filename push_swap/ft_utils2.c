/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:24:07 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/18 16:06:17 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
}

int	is_sorted(t_deque *deq, int size)
{
	int		i;
	int		j;
	int		*val;

	i = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		val = ft_deqget_idx(deq, i);
		while (j < size)
		{
			if (*val > *(int *)ft_deqget_idx(deq, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
