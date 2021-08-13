/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:14:22 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 14:33:33 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	ft_deqadd_front(t_deque *deq, void *content)
{
	t_node	*node;

	if (!deq)
		return ;
	node = ft_deq_newnode(content);
	if (!node)
		return ;
	if (ft_deq_isempty(deq))
		deq->tail = node;
	else
		deq->head->prev = node;
	node->next = deq->head;
	deq->head = node;
}
