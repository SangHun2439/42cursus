/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:05:56 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 15:53:28 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	*ft_deqpop_front(t_deque *deq)
{
	t_node	*head_node;
	void	*res ;

	if (!deq)
		return (0);
	if (ft_deq_isempty(deq))
		return (0);
	head_node = deq->head;
	deq->head = head_node->next;
	if (!deq->head)
		deq->tail = 0;
	else
		deq->head->prev = 0;
	res = head_node->content;
	free(head_node);
	return (res);
}
