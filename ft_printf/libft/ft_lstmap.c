/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:58:05 by sangjeon          #+#    #+#             */
/*   Updated: 2021/08/10 18:45:21 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*header;
	t_list	*cur;

	if (!lst)
		return (0);
	header = ft_lstnew((*f)(lst->content));
	if (!header)
		return (0);
	cur = header;
	lst = lst->next;
	while (lst)
	{
		cur->next = ft_lstnew((*f)(lst->content));
		if (!(cur->next))
		{
			ft_lstclear(&header, del);
			return (0);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (header);
}
