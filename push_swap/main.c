/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:37:56 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/03 19:07:24 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_deq(t_deque *deq)
{
	int	*content;

	while (deq->head)
	{
		content = ft_deqpop_front(deq);
		ft_putnbr_fd(*content, 1);
		ft_putstr_fd("\n", 1);
		del(content);
	}
}

int	err_deal(t_deque *a_deq, t_deque *b_deq)
{
	ft_putstr_fd("Error\n", 2);
	ft_deqclear(&a_deq, del);
	ft_deqclear(&b_deq, del);
	return (1);
}

static void	init(t_deque **p_adeq, t_deque **p_bdeq, int *p_idx, int *p_err)
{
	*p_adeq = ft_deqinit();
	*p_bdeq = ft_deqinit();
	*p_idx = 1;
	*p_err = 0;
}

int	main(int argc, char **argv)
{
	t_deque	*a_deq;
	t_deque *b_deq;
	int		idx;
	int		*content;
	int		err;

	init(&a_deq, &b_deq, &idx, &err);
	while (idx < argc)
	{
		content = (int *)malloc(sizeof(int));
		*content = errcheck_atoi(argv[idx], &err);
		if (err)
			return (err_deal(a_deq, b_deq));
		ft_deqadd_back(a_deq, content);
		idx++;
	}
	dup_check(a_deq, &err);
	if (err)
		return (err_deal(a_deq, b_deq));
	quick_sort(a_deq, b_deq, 0, argc - 2);
	print_deq(a_deq);
	return (1);
}
