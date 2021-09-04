/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 14:32:49 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/03 19:38:08 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_insert_sort(t_deque *a_deq, t_deque *b_deq, t_insert_sort conf)
{
	int	up;
	int	down;

	up = conf.up;
	down = conf.down;
	while (down--)
		rotate(a_deq, b_deq, conf.mod, 0);
	if (conf.mod == 'a')
		push(a_deq, b_deq, 'b', 0);
	else
		push(a_deq, b_deq, 'a', 0);
	down = conf.down - conf.up;
	while (down--)
		revrotate(a_deq, b_deq, conf.mod, 0);
	push(a_deq, b_deq, conf.mod, 0);
	while (up--)
		revrotate(a_deq, b_deq, conf.mod, 0);
}

void	insert_sort(t_deque *a_deq, t_deque *b_deq, int r, char mod)
{
	t_insert_sort	conf;
	t_deque			*target;

	conf.down = 1;
	conf.mod = mod;
	if (mod == 'a')
		target = a_deq;
	else
		target = b_deq;
	while (conf.down < r)
	{
		conf.up = conf.down;
		while (conf.up && *(int *)ft_deqget_idx(target, conf.down) \
		< *(int *)ft_deqget_idx(target, conf.up - 1))
			conf.up--;
		if (conf.up != conf.down)
			swap_insert_sort(a_deq, b_deq, conf);
		conf.down++;
	}
}
