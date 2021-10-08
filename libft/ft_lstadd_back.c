/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:17:03 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/07 18:54:44 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!lst || !(*lst))
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	else if (lst && new)
	{
		last = ft_lstlast(*lst);
		new->next = NULL;
		last->next = new;
	}
}
