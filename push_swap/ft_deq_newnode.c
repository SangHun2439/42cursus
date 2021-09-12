/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_newnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:23:20 by sangjeon          #+#    #+#             */
/*   Updated: 2021/09/12 17:02:52 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

t_node	*ft_deq_newnode(void *content)
{
	t_node	*res;

	res = (t_node *)malloc(sizeof(t_node));
	if (!res)
		exit(0);
	res->content = content;
	res->next = 0;
	res->prev = 0;
	return (res);
}
