/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:35:10 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/04 14:37:00 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	ft_deq_count(t_deque *deq)
{
	t_node	*head;
	int		cnt;

	if (!deq)
		return (-1);
	cnt = 0;
	head = deq->head;
	while (head)
	{
		cnt++;
		head = head->next;
	}
	return (cnt);
}
