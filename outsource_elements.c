/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outsource_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:17:26 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/12 10:17:30 by lhoerger         ###   ########.fr       */
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
}

void	outsource_elements_not_in_sub(t_data *data)
{
	int			i;
	t_list		*list;
	t_content	*content;
	int			intchr;

	i = 0;
	while (i < data->len_list)
	{
		list = data->stack1;
		content = ft_cast_content(list->content);
		intchr = ft_intchr(data->longest_sub, data->len_sub, content->value);
		outsource_elements(content, intchr, data);
		if (content->flag_longest_sub == 0)
			cmd_pb(data);
		else
			cmd_ra(data);
		i++;
	}
}
