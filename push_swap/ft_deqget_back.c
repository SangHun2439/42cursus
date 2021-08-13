/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqget_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:39:17 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/13 14:46:26 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	*ft_deqget_back(t_deque *deq)
{
	if (!deq || ft_deq_isempty(deq))
		return (0);
	return (deq->tail->content);
}
