/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:29:15 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/08 18:04:38 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content	*ft_cast_content(void *content)
{
	return ((t_content *) content);
}

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

void	print_stacks(t_data *data) //Achtung printf, diese Funktion darf nicht mit abgegeben werden
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_content	*content_a;
	t_content	*content_b;

	stack_a = data->stack1;
	stack_b = data->stack2;
	ft_printf("Stack A:    Stack B:\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			content_a = ft_cast_content(stack_a->content);
			printf("%3d        ", content_a->value);
			stack_a = stack_a->next;
		}
		else
			printf("           ");
		if (stack_b != NULL)
		{
			content_b = ft_cast_content(stack_b->content);
			printf("%3d        \n", content_b->value);
			stack_b = stack_b->next;
		}
		else
			printf("        \n");
	}
	for (int i = 0; i < data->len_sub; i++) //Achtung for
		ft_printf("%d, ", data->longest_sub[i]);
	ft_printf("\n");
}

void mark_list_longest_sub(t_data *data)
{
	int	i;
	t_list	*list;
	t_content	*content;
	int intchr;
	int last_found;

	last_found = 0;
	i = 0;
	while (i < data->len_list)
	{
		list = data->stack1;
		content = ft_cast_content(list->content);
		intchr = ft_intchr(data->longest_sub, data->len_sub, content->value);
		
		ft_printf("value: %i, intchr: %i\n", content->value, intchr);
		if (intchr != -1)
		{
			last_found = intchr;
			content->flag_longest_sub = 1;
		}
		else if (content->flag_longest_sub != 1 &&
			ft_intchr(data->longest_sub, data->len_sub, ft_cast_content(list->next->content)->value) != -1 && 
			content->value > data->longest_sub[last_found + 1] && 
			content->value < data->longest_sub[last_found + 2])
		{
			ft_printf("##########################im komplizierten if\n");
			content->flag_longest_sub = 1;
			cmd_sa(data);
			cmd_ra(data);
		}
		ft_printf("listel: value: %i, flag: %i\n", content->value, content->flag_longest_sub);
		if (content->flag_longest_sub == 0)
			cmd_pb(data);
		else
			cmd_ra(data);
		i++;
		
		//print_stacks(data);
	}
}

void	change_stack1(t_data *data)
{
	mark_list_longest_sub(data);
}

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_data	data;

	data.stack1 = NULL;
	data.stack2 = NULL;
	data.len_sub = 0;
	data.len_list = 0;
	ft_bzero(&data, sizeof(data));
	prepare_input(argc, argv, &data);
	data.len_list = ft_lstsize(data.stack1);
	print_stacks(&data);
	//ft_lstprint(data.stack1, 1);
	//ft_lstprint(data.stack2, 2);
	get_longest_subsequence(&data);
	//print_int_arr(data.longest_sub, data.len_sub);
	change_stack1(&data);
	print_stacks(&data);
	//ft_printf("################################\n");
	////cmd_sa(&data);
	//cmd_pb(&data);
	//ft_lstprint(data.stack1, 1);
	//ft_lstprint(data.stack2, 2);
	//ft_printf("################################\n");
	//cmd_pa(&data);
	//ft_lstprint(data.stack1, 1);
	//ft_lstprint(data.stack2, 2);
	//ft_printf("################################\n");
	//cmd_ss(&data);
	//ft_lstprint(data.stack1, 1);
	//ft_lstprint(data.stack2, 2);
	//ft_printf("################################\n");
	//cmd_rrr(&data);
	//ft_lstprint(data.stack1, 1);
	//ft_lstprint(data.stack2, 2);
	//ft_del_stack(data.stack1);
	// system("leaks push_swap");
	return (0);
}
