/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:21:22 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/12 14:19:20 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sorted(t_data *data, int flag)
{
	t_list	*list;
	int		prev;

	list = data->stack1->next;
	prev = ft_cast_content(data->stack1->content)->value;
	while (list)
	{
		if (ft_cast_content(list->content)->value < prev)
		{
			if (flag == 1)
			{
				write(1, "KO\n", 3);
				exit(1);
			}
			else
				return ;
		}
		prev = ft_cast_content(list->content)->value;
		list = list->next;
	}
	write(1, "OK\n", 3);
	exit(0);
}

void	execute_cmd(t_data *data, char *str)
{
	if (ft_strncmp(str, "ra\n", 5) == 0)
		cmd_ra(data);
	else if (ft_strncmp(str, "rb\n", 5) == 0)
		cmd_rb(data);
	else if (ft_strncmp(str, "rr\n", 5) == 0)
		cmd_rr(data);
	else if (ft_strncmp(str, "rrb\n", 5) == 0)
		cmd_rrb(data);
	else if (ft_strncmp(str, "rra\n", 5) == 0)
		cmd_rra(data);
	else if (ft_strncmp(str, "rrr\n", 5) == 0)
		cmd_rrr(data);
	else if (ft_strncmp(str, "pb\n", 5) == 0)
		cmd_pb(data);
	else if (ft_strncmp(str, "pa\n", 5) == 0)
		cmd_pa(data);
	else if (ft_strncmp(str, "sa\n", 5) == 0)
		cmd_sa(data);
	else if (ft_strncmp(str, "sb\n", 5) == 0)
		cmd_sb(data);
	else
	{
		write(2, "ERROR\n", 6);
		exit(1);
	}
}

void	execute_cmds(t_data *data)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		execute_cmd(data, str);
		ft_free_1d((void **) &str);
		str = get_next_line(0);
	}
	ft_free_1d((void **) &str);
}

void	check_stackb_empty(t_data *data)
{
	if (data->stack2)
	{
		write(1, "KO\n", 3);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.stack1 = NULL;
	data.stack2 = NULL;
	data.len_sub = 0;
	data.len_list = 0;
	ft_bzero(&data, sizeof(data));
	prepare_input(argc, argv, &data);
	check_sorted(&data, 0);
	execute_cmds(&data);
	check_stackb_empty(&data);
	check_sorted(&data, 1);
}
