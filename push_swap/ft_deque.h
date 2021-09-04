/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:16:32 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/28 17:10:24 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include <stdlib.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
}	t_deque;

int		ft_deq_isempty(t_deque *deq);
t_node	*ft_deq_newnode(void *content);
void	ft_deqadd_back(t_deque *deq, void *content);
void	ft_deqadd_front(t_deque *deq, void *content);
void	ft_deqclear(t_deque **p_deq, void (*del)(void *));
void	*ft_deqget_back(t_deque *deq);
void	*ft_deqget_front(t_deque *deq);
void	*ft_deqget_idx(t_deque *deq, int idx);
void	*ft_deqpop_back(t_deque *deq);
void	*ft_deqpop_front(t_deque *deq);
t_deque	*ft_deqinit(void);

#endif
