/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:37:56 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/06 23:36:51 by sangjeon         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_deque	*a_deq;
	t_deque	*b_deq;
	int		err;

	if (argc == 1)
		return (1);
	a_deq = ft_deqinit();
	b_deq = ft_deqinit();
	err = 0;
	input(argc, argv, a_deq, &err);
	if (err)
		return (err_deal(a_deq, b_deq));
	dup_check(a_deq, &err);
	if (err)
		return (err_deal(a_deq, b_deq));
	quick_sort(a_deq, b_deq);
	// print_deq(a_deq);
	// ft_deqclear(&a_deq, del);
	// ft_deqclear(&b_deq, del);
	return (1);
}
