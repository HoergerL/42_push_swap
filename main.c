/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:29:15 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/12 14:14:40 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_content(t_content *content)
{
	ft_printf("value: %i\n", content->value);
}

void	ft_lstprint(t_list *list, int nr)
{
	ft_printf("List: %i\n", nr);
	if (!list)
		return ;
	while (list)
	{
		ft_print_content(list->content);
		list = (list)->next;
	}
	ft_printf("\n\n");
}

//void	print_stacks(t_data *data) 
//{
//	t_list		*stack_a;
//	t_list		*stack_b;
//	t_content	*content_a;
//	t_content	*content_b;

//	stack_a = data->stack1;
//	stack_b = data->stack2;
//	ft_printf("Stack A:    Stack B:\n");
//	while (stack_a != NULL || stack_b != NULL)
//	{
//		if (stack_a != NULL)
//		{
//			content_a = ft_cast_content(stack_a->content);
//			printf("%3d        ", content_a->value);
//			stack_a = stack_a->next;
//		}
//		else
//			printf("           ");
//		if (stack_b != NULL)
//		{
//			content_b = ft_cast_content(stack_b->content);
//			printf("%3d        \n", content_b->value);
//			stack_b = stack_b->next;
//		}
//		else
//			printf("        \n");
//	}
//	for (int i = 0; i < data->len_sub; i++) //Achtung for
//		ft_printf("%d, ", data->longest_sub[i]);
//	ft_printf("\n");
//}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.stack1 = NULL;
	data.stack2 = NULL;
	data.len_sub = 0;
	data.len_list = 0;
	ft_bzero(&data, sizeof(data));
	prepare_input(argc, argv, &data);
	data.len_list = ft_lstsize(data.stack1);
	check_already_sorted(&data);
	handle_short_lists(&data);
	get_longest_subsequence(&data);
	outsource_elements_not_in_sub(&data);
	push_back(&data);
	bring_into_right_order(&data);
	return (0);
}
