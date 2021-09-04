/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:17:36 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/04 14:23:51 by sangjeon         ###   ########.fr       */
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
void	do_sort(t_deque *a_deq, t_deque *b_deq, int *err);
int		sort_check(t_deque *a_deq, t_deque *b_deq);
int		get_next_line(int fd, char **line);
void	input(int argc, char **argv, t_deque *a_deq, int *p_err);

#endif
