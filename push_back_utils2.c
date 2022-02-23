/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 09:55:29 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/12 09:55:37 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_optimal_element(t_data *data)
{
	ft_execute_rotates(data);
	ft_execute_reverse_rotates(data);
	cmd_pa(data);
}

void	push_back(t_data *data)
{

	while (1)
	{
		if (data->stack2 == NULL)
			break ;
		define_biggest_smallest_el_stack1(data);
		calc_optimal_push_back(data);
		push_back_optimal_element(data);
	}
}
