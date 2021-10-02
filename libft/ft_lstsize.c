/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:51:18 by lhoerger          #+#    #+#             */
/*   Updated: 2021/06/24 09:44:31 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*lstel;

	i = 1;
	lstel = lst;
	if (!lst)
		return (0);
	while (lstel->next)
	{
		lstel = lstel->next;
		i++;
	}
	return (i);
}
