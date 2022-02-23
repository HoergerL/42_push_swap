/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:08:24 by lhoerger          #+#    #+#             */
/*   Updated: 2022/02/23 15:32:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_correct_place_for_el(t_data *data, t_list *list)
{
	int		srch;
	t_list	*stack1;
	int		prev_el;
	int		index;

	index = 0;
	stack1 = data->stack1;
	srch = ft_cast_content(list->content)->value;
	prev_el = ft_cast_content(stack1->content)->value;
	while (stack1)
	{
		if (srch > prev_el && srch < ft_cast_content(stack1->content)->value)
			return (index);
		else if ((srch > data->big_el_1 && prev_el == data->big_el_1)
			|| (srch < data->smal_el_1 && prev_el == data->big_el_1))
		{
			if (index == 0)
				return (1);
			return (index);
		}
		prev_el = ft_cast_content(stack1->content)->value;
		stack1 = stack1->next;
		index++;
	}
	return (0);
}

int	calc_steps(t_data *data, t_list *list, int index)
{
	int	index_target;
	int	rotations_needed;

	index_target = find_correct_place_for_el(data, list);
	rotations_needed = calc_rot(data, index, index_target, list);
	return (rotations_needed);
}

int	calc_optimal_push_back(t_data *data)
{
	t_list	*list;
	int		min;
	int		temp_min;
	int		index;

	index = 0;
	min = INT_MAX;
	list = data->stack2;
	while (index < ft_lstsize(data->stack2))
	{
		temp_min = calc_steps(data, list, index);
		if (temp_min < min)
		{
			min = temp_min;
			data->nbr_to_move = ft_cast_content(list->content)->value;
			data->flag_mvmnt = ft_cast_content(list->content)->flag_mvmnt;
		}
		index++;
		list = list->next;
	}
	return (min);
}
