/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:11:36 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 17:31:37 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	ft_deqclear(t_deque **p_deq, void (*del)(void *))
{
	if (!p_deq)
		return ;
	while ((*p_deq)->head)
		del(ft_deqpop_front(*p_deq));
	free(*p_deq);
	*p_deq = 0;
}
