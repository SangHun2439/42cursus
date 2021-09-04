/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:04:45 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/03 19:37:36 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(t_deque *a_deq, t_deque *b_deq, int up, int down)
{
	int	res;
	int	idx;
	int	pivot;
	int	rotate_count;

	idx = 0;
	rotate_count = 0;
	res = up;
	while (idx < up)
	{
		rotate(a_deq, b_deq, 'a', 0);
		idx++;
	}
	pivot = *(int *)ft_deqget_front(a_deq);
	while (idx < down + 1)
	{
		if (pivot > *(int *)ft_deqget_front(a_deq))
		{
			push(a_deq, b_deq, 'b', 0);
			res++;
		}
		else
		{
			rotate(a_deq, b_deq, 'a', 0);
			rotate_count++;
		}
		idx++;
	}
	idx = res - up;
	while (rotate_count--)
		revrotate(a_deq, b_deq, 'a', 0);
	while (idx--)
		push(a_deq, b_deq, 'a', 0);
	while (up--)
		revrotate(a_deq, b_deq, 'a', 0);
	return (res);
}

void	quick_sort(t_deque *a_deq, t_deque *b_deq, int up, int down)
{
	int	pivot;

	if (up < down)
	{
		pivot = partition(a_deq, b_deq, up, down);
		quick_sort(a_deq, b_deq, up, pivot - 1);
		quick_sort(a_deq, b_deq, pivot + 1, down);
	}
}
