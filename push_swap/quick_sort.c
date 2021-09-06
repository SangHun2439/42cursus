/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:04:45 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/07 00:35:44 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	div_three(t_deque *deq, int size, int *one_third, int *two_third)
{
	int		one;
	int		two;
	int		*arr;
	int		idx;

	one = size / 3;
	two = one * 2;
	idx = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	while (idx < size)
	{
		arr[idx] = *(int *)ft_deqget_idx(deq, idx);
		idx++;
	}
	*one_third = quick_select(arr, 0, size - 1, one - 1);
	*two_third = quick_select(arr, 0, size - 1, two - 1);
	free(arr);
}

static void	init(t_cnt *p_cnt, int size, int piv_one, int piv_two)
{
	p_cnt->pa = 0;
	p_cnt->pb = 0;
	p_cnt->ra = 0;
	p_cnt->rb = 0;
	p_cnt->size = size;
	p_cnt->piv_one = piv_one;
	p_cnt->piv_two = piv_two;
}

void	partition_a(t_deque *a_deq, t_deque *b_deq, int size)
{
	int		piv_one;
	int		piv_two;
	t_cnt	cnt;

	if (size < 3)
		return hard_sort_a(a_deq, b_deq, size);
	div_three(a_deq, size, &piv_one, &piv_two);
	init(&cnt, size, piv_one, piv_two);
	while (size--)
		a_push_rotate(a_deq, b_deq, &cnt);
	many_rev(a_deq, b_deq, cnt.ra, 'a');
	many_rev(a_deq, b_deq, cnt.rb, 'b');
	partition_a(a_deq, b_deq, cnt.ra);
	partition_b(a_deq, b_deq, cnt.rb);
	partition_b(a_deq, b_deq, cnt.pb - cnt.rb);
}

void	partition_b(t_deque *a_deq, t_deque *b_deq, int size)
{
	int		piv_one;
	int		piv_two;
	t_cnt	cnt;

	if (size < 3)
		return hard_sort_b(a_deq, b_deq, size);
	div_three(b_deq, size, &piv_one, &piv_two);
	init(&cnt, size, piv_one, piv_two);
	while (size--)
		b_push_rotate(a_deq, b_deq, &cnt);
	many_rev(a_deq, b_deq, cnt.rb, 'b');
	partition_a(a_deq, b_deq, cnt.pa - cnt.ra);
	many_rev(a_deq, b_deq, cnt.ra, 'a');
	partition_a(a_deq, b_deq, cnt.ra);
	partition_b(a_deq, b_deq, cnt.rb);
}

void	quick_sort(t_deque *a_deq, t_deque *b_deq)
{
	int	size;

	size = ft_deq_count(a_deq);
	partition_a(a_deq, b_deq, size);
}
