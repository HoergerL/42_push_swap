/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:39:08 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/12 10:16:16 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_into_right_order(t_data *data)
{
	t_list	*list;
	int		index;

	define_biggest_smallest_el_stack1(data);
	list = data->stack1;
	while (list)
	{
		if (ft_cast_content(list->content)->value == data->smal_el_1)
			break ;
		index++;
		list = list->next;
	}
	if (index < ft_lstsize(data->stack1) / 2)
	{
		while (ft_cast_content(data->stack1->content)->value != data->smal_el_1)
			cmd_ra(data);
	}
	else
	{
		while (ft_cast_content(data->stack1->content)->value != data->smal_el_1)
			cmd_rra(data);
	}
}

int	check_already_sorted(t_data *data)
{
	t_list	*list;
	int		prev;

	list = data->stack1->next;
	prev = ft_cast_content(data->stack1->content)->value;
	while (list)
	{
		if (ft_cast_content(list->content)->value < prev)
			return (1);
		prev = ft_cast_content(list->content)->value;
		list = list->next;
	}
	exit(0);
}

void	handle_short_lists(t_data *data)
{
	t_list		*listel;
	t_content	*content_next;
	t_content	*content;

	content = ft_cast_content(listel->content);
	content_next = ft_cast_content(listel->next->content);
	if (ft_lstsize(data->stack1) < 4)
	{
		listel = data->stack1;
		while (check_already_sorted(data))
		{
			if (listel->next
				&& content_next->value < content->value)
				cmd_sa(data);
			else
				cmd_rra(data);
		}
	}
}
