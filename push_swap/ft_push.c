/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:06:12 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/03 19:34:47 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_deque *from, t_deque *to)
{
	if (ft_deq_isempty(from))
		return ;
	ft_deqadd_front(to, ft_deqpop_front(from));
}

void	pa(t_deque *a_deq, t_deque *b_deq, char silent)
{
	do_push(b_deq, a_deq);
	if (!silent)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_deque *a_deq, t_deque *b_deq, char silent)
{
	do_push(a_deq, b_deq);
	if (!silent)
		ft_putstr_fd("pb\n", 1);
}

void	push(t_deque *a_deq, t_deque *b_deq, char mod, char silent)
{
	if (mod == 'a')
		pa(a_deq, b_deq, silent);
	else if (mod == 'b')
		pb(a_deq, b_deq, silent);
}
