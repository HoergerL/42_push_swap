/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:39:45 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/12 10:11:50 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_biggest_smallest_el_stack1(t_data *data)
{
	t_list	*list;
	int		temp;

	data->big_el_1 = INT_MIN;
	data->smal_el_1 = INT_MAX;
	list = data->stack1;
	while (list)
	{
		temp = ft_cast_content(list->content)->value;
		if (data->big_el_1 < temp)
			data->big_el_1 = temp;
		if (data->smal_el_1 > temp)
			data->smal_el_1 = temp;
		list = list->next;
	}
}

t_list	*lst_find_el_by_value(t_list *list, int value)
{
	t_list	*listel;

	listel = list;
	while (listel)
	{
		if (ft_cast_content(listel->content)->value == value)
			return (listel);
		listel = listel->next;
	}
	return (0);
}

void	ft_execute_rotates(t_data *data)
{
	t_list		*list;
	t_content	*content;

	list = lst_find_el_by_value(data->stack2, data->nbr_to_move);
	content = ft_cast_content(list->content);
	while (content->flag_mvmnt_rr > 0)
	{
		cmd_rr(data);
		content->flag_mvmnt_rr = content->flag_mvmnt_rr - 1;
	}
	while (content->flag_mvmnt_rb > 0)
	{
		cmd_rb(data);
		content->flag_mvmnt_rb = content->flag_mvmnt_rb - 1;
	}
	while (content->flag_mvmnt_ra > 0)
	{
		cmd_ra(data);
		content->flag_mvmnt_ra = content->flag_mvmnt_ra - 1;
	}
}

void	ft_execute_reverse_rotates(t_data *data)
{
	t_list		*list;
	t_content	*content;

	list = lst_find_el_by_value(data->stack2, data->nbr_to_move);
	content = ft_cast_content(list->content);
	while (content->flag_mvmnt_rrr > 0)
	{
		cmd_rrr(data);
		content->flag_mvmnt_rrr = content->flag_mvmnt_rrr - 1;
	}
	while (content->flag_mvmnt_rra > 0)
	{
		cmd_rra(data);
		content->flag_mvmnt_rra = content->flag_mvmnt_rra - 1;
	}
	while (content->flag_mvmnt_rrb > 0)
	{
		cmd_rrb(data);
		content->flag_mvmnt_rrb = content->flag_mvmnt_rrb - 1;
	}
}
