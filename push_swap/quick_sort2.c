/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:04:29 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/06 23:17:06 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	hard_sort_a(t_deque *a_deq, t_deque *b_deq, int size)
{
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (*(int *)a_deq->head->content < *(int *)a_deq->head->next->content)
			return ;
		else
		{
			swap(a_deq, b_deq, 'a', 0);
			return ;
		}
	}
}

void	hard_sort_b(t_deque *a_deq, t_deque *b_deq, int size)
{
	if (size == 1)
	{
		push(a_deq, b_deq, 'a', 0);
		return ;
	}
	if (size == 2)
	{
		if (*(int *)b_deq->head->content < *(int *)b_deq->head->next->content)
			swap(a_deq, b_deq, 'b', 0);
		while(size--)
			push(a_deq, b_deq, 'a', 0);
		return ;
	}
}

void	a_push_rotate(t_deque *a_deq, t_deque *b_deq, t_cnt *p_cnt)
{
	if (*(int *)a_deq->head->content > p_cnt->piv_two)
	{
		rotate(a_deq, b_deq, 'a', 0);
		p_cnt->ra++;
	}
	else
	{
		push(a_deq, b_deq, 'b', 0);
		p_cnt->pb++;
		if (*(int *)b_deq->head->content > p_cnt->piv_one)
		{
			rotate(a_deq, b_deq, 'b', 0);
			p_cnt->rb++;
		}
	}
}

void	b_push_rotate(t_deque *a_deq, t_deque *b_deq, t_cnt *p_cnt)
{
	if (*(int *)b_deq->head->content <= p_cnt->piv_one)
	{
		rotate(a_deq, b_deq, 'b', 0);
		p_cnt->rb++;
	}
	else
	{
		push(a_deq, b_deq, 'a', 0);
		p_cnt->pa++;
		if (*(int *)a_deq->head->content <= p_cnt->piv_two)
		{
			rotate(a_deq, b_deq, 'a', 0);
			p_cnt->ra++;
		}
	}
}

void	many_rev(t_deque *a_deq, t_deque *b_deq, int num, char mod)
{
	while (num--)
		revrotate(a_deq, b_deq, mod, 0);
}
