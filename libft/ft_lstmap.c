/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:30:11 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/24 09:43:54 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*new_el;

	if (lst == NULL)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		new_el = ft_lstnew((*f)(lst->content));
		if (!new_el)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, new_el);
		new_el = new_el->next;
		lst = lst->next;
	}
	return (newlist);
}
