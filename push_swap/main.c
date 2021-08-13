/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:37:56 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 17:47:19 by sangjeon         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_deque	*a_deq;
	t_deque *b_deq;
	int		idx;
	int		*content;
	int		err;

	a_deq = ft_deqinit();
	b_deq = ft_deqinit();
	idx = 1;
	err = 0;
	while (idx < argc)
	{
		content = (int *)malloc(sizeof(int));
		*content = errcheck_atoi(argv[idx], &err);
		if (err)
		{
			ft_putstr_fd("Error\n", 1);
			ft_deqclear(&a_deq, del);
			return (1);
		}
		ft_deqadd_front(a_deq, content);
		idx++;
	}
	revrotate(a_deq, b_deq, 'a');
	ft_putstr_fd("a\n", 1);
	print_deq(a_deq);
	ft_putstr_fd("b\n", 1);
	print_deq(b_deq);
	return (1);
}