/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:25:14 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/03 17:12:19 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content	*ft_cast_content(void *content)
{
	return ((t_content *) content);
}

void	ft_print_content(t_content *content)
{
	//ft_printf("\nList content: \n");
	ft_printf("value: %i\n", content->value);
}

void	ft_lstprint(t_list *list, int nr)
{
	ft_printf("List: %i\n", nr);
	if(!list)
		return ;
	while (list)
	{
		ft_print_content(list->content);
		list = (list)->next;
	}
	ft_printf("\n\n");
}

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_data	data;

	data.stack1 = NULL;
	data.stack2 = NULL;
	ft_bzero(&data, sizeof(data));
	prepare_input(argc, argv, &data);
	ft_lstprint(data.stack1, 1);
	ft_lstprint(data.stack2, 2);
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
	ft_printf("################################\n");
	cmd_rrr(&data);
	ft_lstprint(data.stack1, 1);
	ft_lstprint(data.stack2, 2);
	//ft_del_stack(data.stack1);
	//system("leaks push_swap");
	return (0);
}
