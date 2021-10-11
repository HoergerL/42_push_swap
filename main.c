/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:29:15 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/11 16:02:01 by lhoerger         ###   ########.fr       */
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
int get_lowest_rotation(int total_reverse, int total, int ra_rrb, int rb_rra, t_list *list)
{
	if (total_reverse <= total && total_reverse <= ra_rrb && total_reverse <= rb_rra)
	{
		//ft_printf("lowest is total_reverse\n");
		ft_cast_content(list->content)->flag_movement = REVERSE_ROTATE;
		return (total_reverse);
	}
	if (total <= total_reverse && total <= ra_rrb && total <= rb_rra)
	{
		//ft_printf("lowest is total\n");
		ft_cast_content(list->content)->flag_movement = ROTATE;
		return (total);
	}
	if (ra_rrb <= total_reverse && ra_rrb <= total && ra_rrb <= rb_rra)
	{
		//ft_printf("lowest is ra_rrb\n");
		ft_cast_content(list->content)->flag_movement = RA_RRB;
		return (ra_rrb);
	}
	else
	{
		//ft_printf("lowest is rb_rra\n");
		ft_cast_content(list->content)->flag_movement = RB_RRA;
		return (rb_rra);
	}
}

void truncate_flag_movements(t_data *data, t_list *list)
{
	ft_cast_content(list->content)->flag_movement_ra = 0;
	ft_cast_content(list->content)->flag_movement_rb = 0;
	ft_cast_content(list->content)->flag_movement_rr = 0;
	ft_cast_content(list->content)->flag_movement_rra = 0;
	ft_cast_content(list->content)->flag_movement_rrb = 0;
	ft_cast_content(list->content)->flag_movement_rrr = 0;
}

void fill_data(t_data *data, t_movement *movement, t_list *list)
{
	//ft_printf("filldata:\nras: %i\nrbs: %i\nrras: %i\nrrbs: %i\n", movement->ras,movement->rbs, movement->rras, movement->rrbs);
	if (ft_cast_content(list->content)->flag_movement == ROTATE)
	{
		if(movement->rbs > movement->ras)
			ft_cast_content(list->content)->flag_movement_rr = movement->ras;
		else
			ft_cast_content(list->content)->flag_movement_rr = movement->rbs;
		ft_cast_content(list->content)->flag_movement_ra = movement->ras - ft_cast_content(list->content)->flag_movement_rr;
		ft_cast_content(list->content)->flag_movement_rb = movement->rbs - ft_cast_content(list->content)->flag_movement_rr;
	}
	else if (ft_cast_content(list->content)->flag_movement  == REVERSE_ROTATE)
	{
		if(movement->rrbs > movement->rras)
			ft_cast_content(list->content)->flag_movement_rrr = movement->rras;
		else
			ft_cast_content(list->content)->flag_movement_rrr = movement->rrbs;
		ft_cast_content(list->content)->flag_movement_rra = movement->rras - ft_cast_content(list->content)->flag_movement_rrr;
		ft_cast_content(list->content)->flag_movement_rrb = movement->rrbs - ft_cast_content(list->content)->flag_movement_rrr;
	}
	else if (ft_cast_content(list->content)->flag_movement  == RA_RRB)
	{
		ft_cast_content(list->content)->flag_movement_ra = movement->ras;
		ft_cast_content(list->content)->flag_movement_rrb = movement->rrbs;
	}
	else if (ft_cast_content(list->content)->flag_movement  == RB_RRA)
	{
		ft_cast_content(list->content)->flag_movement_rra = movement->rras;
		ft_cast_content(list->content)->flag_movement_rb = movement->rbs;
	}
}

int	calc_rotations(t_data *data, int index_src, int index_dst, t_list *list)
{
	t_movement	movement;
	int			lowest;
	
	ft_bzero(&movement, sizeof(t_movement));
	truncate_flag_movements(data, list);
	movement.rbs = index_src;
	movement.rrbs = ft_lstsize(data->stack2) - index_src;
	if(ft_lstsize(data->stack2) == 1)
		movement.rrbs = 0;
	//ft_printf("rbs: %i, rrbs: %i\n", movement.rbs, movement.rrbs);
	movement.ras = index_dst;
	movement.rras	= ft_lstsize(data->stack1) - index_dst;
	//ft_printf("ras: %i, rras: %i\n", movement.ras, movement.rras);
	if(movement.rrbs > movement.rras)
		movement.total_reverse = movement.rrbs;
	else
		movement.total_reverse = movement.rras;
	if(movement.rbs > movement.ras)
		movement.total = movement.rbs;
	else
		movement.total = movement.ras;
	movement.ra_rrb = movement.ras + movement.rrbs;
	movement.rb_rra = movement.rbs + movement.rras;
	//ft_printf("total_reverse: %i\ntotal: %i\nra-rrb: %i\nrb_rra: %i\n", movement.total_reverse, movement.total, movement.ra_rrb, movement.rb_rra);
	//ft_cast_content(list->content)->flag_movement = get_lowest_rotation(total_reverse, total, ra_rrb, rb_rra);
	lowest = get_lowest_rotation(movement.total_reverse, movement.total, movement.ra_rrb, movement.rb_rra, list);
	fill_data(data, &movement, list);
	return (lowest);
}

int	find_correct_place_for_el(t_data *data, t_list *list)
{
	int		to_search;
	t_list	*stack1;
	int		prev_element;
	int		index;

	index = 0;
	stack1 = data->stack1;
	to_search = ft_cast_content(list->content)->value;
	prev_element = ft_cast_content(stack1->content)->value;
	while (stack1)
	{
		if (to_search > prev_element && to_search < ft_cast_content(stack1->content)->value)
			return (index);
		else if ((to_search > data->biggest_el_stack1 && prev_element == data->biggest_el_stack1)
			|| (to_search < data->smallest_el_stack1 && prev_element == data->biggest_el_stack1))
		{
			if (index == 0)
				return (1);
			return (index);
		}
		prev_element = ft_cast_content(stack1->content)->value;
		stack1 = stack1->next;
		index++;
	}
	return (0);
}

int	calc_steps(t_data *data,t_list *list, int index)
{
	int	index_target;
	int	rotations_needed;

	index_target = find_correct_place_for_el(data, list);
	//ft_printf("\n\nindex target: %i\n", index_target);
	rotations_needed = calc_rotations(data, index, index_target, list);
	return (rotations_needed);
}

int	calc_optimal_push_back(t_data *data)
{
	t_list	*list;
	int		min;
	int		temp_min;
	int		min_nbr;
	int index;

	index = 0;
	min = INT_MAX;
	list = data->stack2;
	while (index < ft_lstsize(data->stack2))
	{
		//ft_printf("\n\nelement in list: %i\n", ft_cast_content(list->content)->value);
		temp_min = calc_steps(data, list, index);
		if(temp_min < min)
		{
			min = temp_min;
			data->nbr_to_move = ft_cast_content(list->content)->value;
			data->flag_movement = ft_cast_content(list->content)->flag_movement;
		}
		index++;
		list = list->next;
	}
	return (min);
}

void define_biggest_smallest_el_stack1(t_data *data)
{
	t_list	*list;
	int		temp;

	data->biggest_el_stack1 = INT_MIN;
	data->smallest_el_stack1 = INT_MAX;
	list = data->stack1;
	while (list)
	{
		temp = ft_cast_content(list->content)->value;
		if (data->biggest_el_stack1 < temp)
			data->biggest_el_stack1= temp;
		if (data->smallest_el_stack1 > temp)
			data->smallest_el_stack1 = temp;
		list = list->next;
	}
	//ft_printf("smallest el: %i, biggest_el: %i\n", data->smallest_el_stack1, data->biggest_el_stack1);
}

t_list	*lst_find_el_by_value(t_list *list, int value)
{
	t_list *listel;

	listel = list;
	while (listel)
	{
		if (ft_cast_content(listel->content)->value == value)
			return (listel);
		listel = listel->next;
	}
	return (0);
}

void push_back_optimal_element(t_data *data)
{
	t_list	*list;
	t_content	*content;

	list = lst_find_el_by_value(data->stack2, data->nbr_to_move);
	content = ft_cast_content(list->content);
	//ft_printf("push back\nras: %i\nrbs: %i\nrr: %i\nrras: %i\nrrbs: %i\nrrrs: %i\n", content->flag_movement_ra,content->flag_movement_rb, content->flag_movement_rr, content->flag_movement_rra, content->flag_movement_rrb, content->flag_movement_rrr);
	while (content->flag_movement_rr > 0)
	{
		cmd_rr(data);
		content->flag_movement_rr = content->flag_movement_rr -1;
	}
	while (content->flag_movement_rrr > 0)
	{
		cmd_rrr(data);
		content->flag_movement_rrr = content->flag_movement_rrr -1;
	}
	while (content->flag_movement_rb > 0)
	{
		cmd_rb(data);
		content->flag_movement_rb = content->flag_movement_rb -1;
	}
	while (content->flag_movement_ra > 0)
	{
		cmd_ra(data);
		content->flag_movement_ra = content->flag_movement_ra -1;
	}
	while (content->flag_movement_rra > 0)
	{
		cmd_rra(data);
		content->flag_movement_rra = content->flag_movement_rra -1;
	}
	while (content->flag_movement_rrb > 0)
	{
		cmd_rrb(data);
		content->flag_movement_rrb = content->flag_movement_rrb -1;
	}
	cmd_pa(data);
	
}

void	push_back(t_data *data)
{
	int	nbr_rotates;

	while(1)
	{
		if (data->stack2 == NULL)
			break;
		//print_stacks(data);
		define_biggest_smallest_el_stack1(data);
		nbr_rotates = calc_optimal_push_back(data);
		//ft_printf("number of rotates: %i, which rotates:%i, which rotation: %i\n\n", nbr_rotates, data->nbr_to_move, data->flag_movement);
		push_back_optimal_element(data);
	}
}

void bring_into_right_order(t_data *data)
{
	t_list	*list;
	int		index;

	define_biggest_smallest_el_stack1(data);
	list = data->stack1;
	while(list)
	{
		if (ft_cast_content(list->content)->value == data->smallest_el_stack1)
			break;
		index++;
		list= list->next;
	}
	//ft_printf("index:%i, smallest el: %i",index, data->smallest_el_stack1);
	if (index < ft_lstsize(data->stack1)/ 2)
	{
		while (ft_cast_content(data->stack1->content)->value != data->smallest_el_stack1)
		{
			cmd_ra(data);
			//print_stacks(data);
			//ft_printf("value: %i, smallest: %i", ft_cast_content(data->stack1)->value,data->smallest_el_stack1);
		}
	}
	else
	{
		while (ft_cast_content(data->stack1->content)->value != data->smallest_el_stack1)
		{
			cmd_rra(data);
			//print_stacks(data);
			//ft_printf("value: %i, smallest: %i", ft_cast_content(data->stack1)->value,data->smallest_el_stack1);
		}
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
	data.len_list = ft_lstsize(data.stack1);
	//print_stacks(&data);
	//ft_lstprint(data.stack1, 1);
	//ft_lstprint(data.stack2, 2);
	get_longest_subsequence(&data);
	//print_int_arr(data.longest_sub, data.len_sub);
	outsource_elements_not_in_sub(&data);
	//print_stacks(&data);
	push_back(&data);
	//print_stacks(&data);
	bring_into_right_order(&data);
	//print_stacks(&data);
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
	//system("leaks push_swap");
	return (0);
}
