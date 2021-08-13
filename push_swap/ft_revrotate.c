/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:40:52 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 17:44:44 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_revrotate(t_deque *deq)
{
	if (ft_deq_isempty(deq) || !(deq->head->next))
		return ;
	ft_deqadd_front(deq, ft_deqpop_back(deq));
}

void	rra(t_deque *a_deq)
{
	do_revrotate(a_deq);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_deque *b_deq)
{
	do_revrotate(b_deq);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_deque *a_deq, t_deque *b_deq)
{
	do_revrotate(a_deq);
	do_revrotate(b_deq);
	ft_putstr_fd("rrr\n", 1);
}

void	revrotate(t_deque *a_deq, t_deque *b_deq, char mod)
{
	if (mod == 'a')
		rra(a_deq);
	else if (mod == 'b')
		rrb(b_deq);
	else if (mod == 's')
		rrr(a_deq, b_deq);
}
