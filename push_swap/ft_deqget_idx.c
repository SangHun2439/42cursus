/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqget_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:04:37 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/29 14:34:23 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	*ft_deqget_idx(t_deque *deq, int idx)
{
	t_node	*node;

	if (!deq || ft_deq_isempty(deq))
		return (0);
	node = deq->head;
	while (idx--)
		node = node->next;
	return (node->content);
}
