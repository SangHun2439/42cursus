/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:19:56 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/18 16:13:14 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ko(t_deque **p_a_deq, t_deque **p_b_deq)
{
	ft_deqclear(p_a_deq, del);
	ft_deqclear(p_b_deq, del);
	ft_putstr_fd("KO\n", 1);
	return (0);
}

int	ok(t_deque **p_a_deq, t_deque **p_b_deq)
{
	ft_deqclear(p_a_deq, del);
	ft_deqclear(p_b_deq, del);
	ft_putstr_fd("OK\n", 1);
	return (0);
}

int	sort_check(t_deque *a_deq, t_deque *b_deq)
{
	int		*val;
	t_node	*head;

	if (!ft_deq_isempty(b_deq))
		return (ko(&a_deq, &b_deq));
	while (!ft_deq_isempty(a_deq))
	{
		val = (int *)ft_deqpop_front(a_deq);
		head = a_deq->head;
		while (head)
		{
			if (*val > *(int *)head->content)
				return (ko(&a_deq, &b_deq));
			head = head->next;
		}
		del(val);
	}
	return (ok(&a_deq, &b_deq));
}

int	intersection(t_deque *a_deq, t_deque *b_deq, char *str)
{
	if (!ft_strncmp(str, "pa", 3))
		push(a_deq, b_deq, 'a', 1);
	else if (!ft_strncmp(str, "pb", 3))
		push(a_deq, b_deq, 'b', 1);
	else if (!ft_strncmp(str, "sa", 3))
		swap(a_deq, b_deq, 'a', 1);
	else if (!ft_strncmp(str, "sb", 3))
		swap(a_deq, b_deq, 'b', 1);
	else if (!ft_strncmp(str, "ss", 3))
		swap(a_deq, b_deq, 's', 1);
	else if (!ft_strncmp(str, "ra", 3))
		rotate(a_deq, b_deq, 'a', 1);
	else if (!ft_strncmp(str, "rb", 3))
		rotate(a_deq, b_deq, 'b', 1);
	else if (!ft_strncmp(str, "rr", 3))
		rotate(a_deq, b_deq, 's', 1);
	else if (!ft_strncmp(str, "rra", 4))
		revrotate(a_deq, b_deq, 'a', 1);
	else if (!ft_strncmp(str, "rrb", 4))
		revrotate(a_deq, b_deq, 'b', 1);
	else if (!ft_strncmp(str, "rrr", 4))
		revrotate(a_deq, b_deq, 's', 1);
	else
		return (0);
	return (1);
}

void	do_sort(t_deque *a_deq, t_deque *b_deq, int *err)
{
	char	*str;
	int		errcheck;

	errcheck = get_next_line(0, &str);
	while (errcheck > 0)
	{
		if (!intersection(a_deq, b_deq, str))
		{
			*err = 1;
			return ;
		}
		free(str);
		errcheck = get_next_line(0, &str);
	}
	if (errcheck < 0)
		*err = 1;
	else
		free(str);
}
