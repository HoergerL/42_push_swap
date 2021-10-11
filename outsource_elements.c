/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outsource_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:48:17 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/11 15:20:12 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	outsource_elements(t_content *content, int intchr, t_data *data)
{
	int static	last_found = 0;

	if (intchr != -1)
	{
		last_found = intchr;
		content->flag_longest_sub = 1;
	}
	//else if (content->flag_longest_sub != 1 &&
	//	ft_intchr(data->longest_sub, data->len_sub, ft_cast_content(data->stack1->next->content)->value) != -1 && 
	//	content->value > data->longest_sub[last_found + 1] && 
	//	content->value < data->longest_sub[last_found + 2])
	//{
	//	content->flag_longest_sub = 1;
	//	cmd_sa(data);
	//	cmd_ra(data);
	//}
}

void outsource_elements_not_in_sub(t_data *data)
{
	int	i;
	t_list	*list;
	t_content	*content;
	int intchr;

	
	i = 0;
	while (i < data->len_list)
	{
		list = data->stack1;
		content = ft_cast_content(list->content);
		intchr = ft_intchr(data->longest_sub, data->len_sub, content->value);
		
		//ft_printf("value: %i, intchr: %i\n", content->value, intchr);
		outsource_elements(content, intchr, data);
		//ft_printf("listel: value: %i, flag: %i\n", content->value, content->flag_longest_sub);
		if (content->flag_longest_sub == 0)
			cmd_pb(data);
		else
			cmd_ra(data);
		//print_stacks(data);
		i++;
	}
}