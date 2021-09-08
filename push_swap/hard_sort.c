/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:33:53 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/08 13:36:03 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_val(t_node *node)
{
	return (*(int *)node->content);
}

void	three_sort(t_deque *a_deq)
{
	t_node	*node;
	int		first;
	int		second;

	first = quick_select_deq(a_deq, 0, 2, 0);
	second = quick_select_deq(a_deq, 0, 2, 1);
	node = a_deq->head;
	if (get_val(node) == second && get_val(node->next) == first)
		swap(a_deq, 0, 'a', 0);
	else if (get_val(node) == second && get_val(node->next->next) == first)
		revrotate(a_deq, 0, 'a', 0);
	else if (get_val(node) == first && get_val(node->next->next) == second)
	{
		revrotate(a_deq, 0, 'a', 0);
		swap(a_deq, 0, 'a', 0);
	}
	else if (get_val(node->next) == first \
	&& get_val(node->next->next) == second)
		rotate(a_deq, 0, 'a', 0);
	else if (get_val(node->next) == second \
	&& get_val(node->next->next) == first)
	{
		swap(a_deq, 0, 'a', 0);
		revrotate(a_deq, 0, 'a', 0);
	}
}

void	five_sort(t_deque *a_deq, t_deque *b_deq)
{
	int		third;
	int		idx;

	idx = 5;
	third = quick_select_deq(a_deq, 0, 4, 2);
	while (idx--)
	{
		if (*(int *)a_deq->head->content < third)
			push(a_deq, b_deq, 'b', 0);
		else
			rotate(a_deq, b_deq, 'a', 0);
	}
	three_sort(a_deq);
	if (*(int *)b_deq->head->content < *(int *)b_deq->head->next->content)
		swap(a_deq, b_deq, 'b', 0);
	push(a_deq, b_deq, 'a', 0);
	push(a_deq, b_deq, 'a', 0);
}

void	four_sort(t_deque *a_deq, t_deque *b_deq)
{
	int		second;
	int		idx;

	idx = 4;
	second = quick_select_deq(a_deq, 0, 3, 1);
	while (idx--)
	{
		if (*(int *)a_deq->head->content < second)
			push(a_deq, b_deq, 'b', 0);
		else
			rotate(a_deq, b_deq, 'a', 0);
	}
	three_sort(a_deq);
	push(a_deq, b_deq, 'a', 0);
}
