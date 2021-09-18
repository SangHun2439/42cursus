/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:04:45 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/18 15:49:41 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	div_three(t_deque *deq, int size, int *one_third, int *two_third)
{
	int		one;
	int		two;

	one = size / 3;
	two = one * 2;
	*one_third = quick_select_deq(deq, 0, size - 1, one - 1);
	*two_third = quick_select_deq(deq, 0, size - 1, two - 1);
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
		return (hard_sort_a(a_deq, b_deq, size));
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
		return (hard_sort_b(a_deq, b_deq, size));
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
	if (is_sorted(a_deq, size))
		return ;
	if (size == 3)
		return (three_sort(a_deq));
	if (size == 4)
		return (four_sort(a_deq, b_deq));
	if (size == 5)
		return (five_sort(a_deq, b_deq));
	partition_a(a_deq, b_deq, size);
}
