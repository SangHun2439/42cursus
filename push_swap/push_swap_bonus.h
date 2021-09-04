/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:17:36 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/03 19:36:55 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "ft_deque.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

int		errcheck_atoi(const char *str, int *err);
void	dup_check(t_deque *deq, int *err);
void	del(void *content);
void	swap(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	push(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	rotate(t_deque *a_deq, t_deque *b_deq, char mod, char silent);
void	revrotate(t_deque *a_deq, t_deque *b_deq, char mod, char silent);

#endif
