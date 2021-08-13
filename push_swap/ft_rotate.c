/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:32:25 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 17:38:40 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_deque *deq)
{
	if (ft_deq_isempty(deq) || !(deq->head->next))
		return ;
	ft_deqadd_back(deq, ft_deqpop_front(deq));
}

void	ra(t_deque *a_deq)
{
	do_rotate(a_deq);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_deque *b_deq)
{
	do_rotate(b_deq);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_deque *a_deq, t_deque *b_deq)
{
	do_rotate(a_deq);
	do_rotate(b_deq);
	ft_putstr_fd("rr\n", 1);
}

void	rotate(t_deque *a_deq, t_deque *b_deq, char mod)
{
	if (mod == 'a')
		ra(a_deq);
	else if (mod == 'b')
		rb(b_deq);
	else if (mod == 's')
		rr(a_deq, b_deq);
}
