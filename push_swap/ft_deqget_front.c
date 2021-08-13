/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqget_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:37:43 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 14:46:11 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	*ft_deqget_front(t_deque *deq)
{
	if (!deq || ft_deq_isempty(deq))
		return (0);
	return (deq->head->content);
}
