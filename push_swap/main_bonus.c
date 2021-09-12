/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:16:44 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/12 17:14:16 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	do_sort(a_deq, b_deq, &err);
	if (err)
		return (err_deal(a_deq, b_deq));
	return (sort_check(a_deq, b_deq));
}
