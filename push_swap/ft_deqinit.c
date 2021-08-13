/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <sangjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:27:23 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/12 22:08:06 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

t_deque	*ft_deqinit(void)
{
	t_deque	*res;

	res = (t_deque *)malloc(sizeof(t_deque));
	if (!res)
		return (0);
	res->head = 0;
	res->tail = 0;
	return (res);
}
