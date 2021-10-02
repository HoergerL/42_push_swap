/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:25:14 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/02 18:44:28 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content	*ft_cast_content(void *content)
{
	return ((t_content *) content);
}

void	ft_print_content(t_content *content)
{
	ft_printf("\nList content: \n");
	ft_printf("value: %i\n\n", content->value);
}

void	ft_lstprint(t_list *list)
{
	while (list)
	{
		ft_print_content(list->content);
		list = (list)->next;
	}
}

void swap(t_list *list)
{
	t_content	*content_temp;

	if (list == NULL || list->next == NULL)
		return ;
	content_temp = list->content;
	list->content = (void *) list->next->content;
	list->next->content = (void *) content_temp;
}

void cmd_sa(t_data *data)
{
	swap(data->stack1);
	write(1, "sa\n", 3);
}

void cmd_sb(t_data *data)
{
	swap(data->stack2);
	write(1, "sb\n", 3);
}

void cmd_ss(t_data *data)
{
	swap(data->stack2);
	swap(data->stack1);
	write(1, "ss\n", 3);
}

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_data	data;

	data.stack1 = NULL;
	data.stack2 = NULL;
	prepare_input(argc, argv, &data);
	ft_lstprint(data.stack1);
	ft_printf("################################");
	cmd_sa(&data);
	ft_lstprint(data.stack1);
	
	ft_del_stack(data.stack1);
	//system("leaks push_swap");
}
