/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjeon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:58:05 by sangjeon          #+#    #+#             */
/*   Updated: 2021/05/15 18:46:10 by sangjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*header;
	t_list	*cur;

	if (!lst)
		return (0);
	if (!(header = ft_lstnew((*f)(lst->content))))
		return (0);
	cur = header;
	lst = lst->next;
	while (lst)
	{
		if (!(cur->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&header, del);
			return (0);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (header);
}
