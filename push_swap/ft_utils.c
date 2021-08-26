/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:03:12 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/26 16:15:27 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
}

static int	error(int *err)
{
	*err = 1;
	return (0);
}

static int	ft_isspace(char chr)
{
	if (chr == '\t')
		return (1);
	if (chr == '\n')
		return (1);
	if (chr == '\v')
		return (1);
	if (chr == '\f')
		return (1);
	if (chr == '\r')
		return (1);
	if (chr == ' ')
		return (1);
	return (0);
}

int	errcheck_atoi(const char *str, int *err)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (error(err));
	}
	if (*str)
		return (error(err));
	return (res * sign);
}

void	dup_check(t_deque *deq, int *err)
{
	t_node	*a_node;
	t_node	*b_node;
	int		val;

	a_node = deq->head;
	while (a_node->next)
	{
		val = *(int *)a_node->content;
		b_node = a_node->next;
		while (b_node)
		{
			if (val == *(int *)b_node->content)
				{
					*err = 1;
					return ;
				}
			b_node = b_node->next;
		}
		a_node = a_node->next;
	}
}
