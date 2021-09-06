/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:32:49 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/06 23:01:37 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_deque.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cnt
{
	int		piv_one;
	int		piv_two;
	int		size;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
}	t_cnt;

int		errcheck_atoi(const char *str, int *err);
void	dup_check(t_deque *deq, int *err);
void	del(void *content);
void	swap(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	push(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	rotate(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	revrotate(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	input(int argc, char **argv, t_deque *a_deq, int *p_err);
void	hard_sort_a(t_deque *a_deq, t_deque *b_deq, int size);
void	hard_sort_b(t_deque *a_deq, t_deque *b_deq, int size);
int		quick_select(int *arr, int start, int end, int k);
void	b_push_rotate(t_deque *a_deq, t_deque *b_deq, t_cnt *p_cnt);
void	a_push_rotate(t_deque *a_deq, t_deque *b_deq, t_cnt *p_cnt);
void	many_rev(t_deque *a_deq, t_deque *b_deq, int num, char mod);
void	quick_sort(t_deque *a_deq, t_deque *b_deq);
void	partition_b(t_deque *a_deq, t_deque *b_deq, int size);
void	partition_a(t_deque *a_deq, t_deque *b_deq, int size);

#endif
