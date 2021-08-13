/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:08:40 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 15:53:19 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	*ft_deqpop_back(t_deque *deq)
{
	t_node	*tail_node;
	void	*res ;

	if (!deq)
		return (0);
	if (ft_deq_isempty(deq))
		return (0);
	tail_node = deq->tail;
	deq->tail = tail_node->prev;
	if (!deq->tail)
		deq->head = 0;
	else
		deq->tail->next = 0;
	res = tail_node->content;
	free(tail_node);
	return (res);
}
