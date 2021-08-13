/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:39:36 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 17:46:26 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_deque *deq)
{
	void	*a;
	void	*b;

	if (ft_deq_isempty(deq) || !(deq->head->next))
		return ;
	a = ft_deqpop_front(deq);
	b = ft_deqpop_front(deq);
	ft_deqadd_front(deq, a);
	ft_deqadd_front(deq, b);
}

void	sa(t_deque *a_deq)
{
	do_swap(a_deq);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_deque *b_deq)
{
	do_swap(b_deq);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_deque *a_deq, t_deque *b_deq)
{
	do_swap(a_deq);
	do_swap(b_deq);
	ft_putstr_fd("ss\n", 1);
}

void	swap(t_deque *a_deq, t_deque *b_deq, char mod)
{
	if (mod == 'a')
		sa(a_deq);
	else if (mod == 'b')
		sa(b_deq);
	else if (mod == 's')
		ss(a_deq, b_deq);
}
