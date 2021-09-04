/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:32:49 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/04 14:23:42 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_deque.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_insert_sort
{
	int		up;
	int		down;
	char	mod;
}	t_insert_sort;

int		errcheck_atoi(const char *str, int *err);
void	dup_check(t_deque *deq, int *err);
void	del(void *content);
void	swap(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	push(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	rotate(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	revrotate(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	insert_sort(t_deque *a_deq, t_deque *b_deq, int r, char mod);
void	quick_sort(t_deque *a_deq, t_deque *b_deq, int up, int down);
void	input(int argc, char **argv, t_deque *a_deq, int *p_err);

#endif
