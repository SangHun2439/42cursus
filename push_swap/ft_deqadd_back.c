/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:33:36 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 14:37:17 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	ft_deqadd_back(t_deque *deq, void *content)
{
	t_node	*node;

	if (!deq)
		return ;
	node = ft_deq_newnode(content);
	if (!node)
		return ;
	if (ft_deq_isempty(deq))
		deq->head = node;
	else
		deq->tail->next = node;
	node->prev = deq->tail;
	deq->tail = node;
}
