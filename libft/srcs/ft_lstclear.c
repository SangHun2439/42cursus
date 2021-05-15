/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:14:29 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/15 11:51:45 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**next;

	while (*lst)
	{
		next = &((*lst)->next);
		del((*lst)->content);
		*lst = 0;
		free(*lst);
		lst = next;
	}
}
