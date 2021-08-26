/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:32:49 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/26 16:07:11 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_deque.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

int		errcheck_atoi(const char *str, int *err);
void	dup_check(t_deque *deq, int *err);
void	del(void *content);
void	swap(t_deque *a_deq, t_deque *b_deq, char mod);
void	push(t_deque *a_deq, t_deque *b_deq, char mod);
void	rotate(t_deque *a_deq, t_deque *b_deq, char mod);
void	revrotate(t_deque *a_deq, t_deque *b_deq, char mod);

#endif
