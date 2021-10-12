/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:20:10 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/11 17:21:09 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **list)
{
	t_list	*temp_list;
	t_list	*listel;

	temp_list = ft_lstlast(*list);
	listel = *list;
	while (listel)
	{
		if (listel->next->next == NULL)
			listel->next = NULL;
		listel = listel->next;
	}
	ft_lstadd_front(list, temp_list);
}

int	cmd_rra(t_data *data)
{
	if (data->stack1 == NULL)
		return (0);
	reverse_rotate(&data->stack1);
	write(1, "rra\n", 4);
	return (1);
}

int	cmd_rrb(t_data *data)
{
	if (data->stack2 == NULL)
		return (0);
	reverse_rotate(&data->stack2);
	write(1, "rrb\n", 4);
	return (1);
}

int	cmd_rrr(t_data *data)
{
	if (data->stack2 == NULL || data->stack1 == NULL)
		return (0);
	reverse_rotate(&data->stack2);
	reverse_rotate(&data->stack1);
	write(1, "rrr\n", 4);
	return (1);
}
