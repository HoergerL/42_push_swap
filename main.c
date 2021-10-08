/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:29:15 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/08 12:01:33 by lhoerger         ###   ########.fr       */
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

int	*intdup(int const *src, size_t len)
{
	int	*p;

	p = malloc(len * sizeof(int));
	if (!p)
		display_error();
	ft_memcpy(p, src, len * sizeof(int));
	return (p);
}

void	print_int_arr(int *arr, int len)
{
	int	k;

	k = 0;
	while (k < len)
	{
		ft_printf("%i, ", arr[k]);
		k++;
	}
	ft_printf("\n");
}

int	*lst_to_arr(t_list *list)
{
	int	len;
	int	*arr;
	int	i;

	len = ft_lstsize(list);
	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		display_error();
	while (list)
	{
		arr[i] = ft_cast_content(list->content)->value;
		list = list->next;
		i++;
	}
	return (arr);
}

void	create_new_max_list(int **solutions, int max_len, int *arr, int i)
{
	//solutions[(*max_len) + 1] = intdup(solutions[(*max_len)], (*max_len) + 2);
	ft_printf("new list created, %i, %i, %p\n", arr[i], max_len, solutions[max_len + 1]);
	ft_memcpy(solutions[max_len + 1], solutions[max_len], sizeof(**solutions) * (max_len + 1));
	solutions[max_len + 1][max_len + 1] = arr[i];
	// (*max_len) = (*max_len) + 1;
	// print_int_arr(solutions[*max_len], *max_len + 1);
}

void	check_subsequence(int max_len, int val, int **solutions)
{
	int	j;

	j = max_len;
	while (j >= 0)
	{
		if (val > solutions[j][j] && val <= solutions[j + 1][j + 1])
		{
			//ft_free_1d((void **)&(solutions[j + 1]));
			//solutions[j + 1] = intdup(solutions[j], j + 2);
			ft_memcpy(solutions[j + 1], solutions[j], sizeof(**solutions) * (j + 1));
			solutions[j + 1][j + 1] = val;
		}
		if (val < solutions[j][j] && ((j == 0) || (val > solutions[j][j - 1])))
			solutions[j][j] = val;
		j--;
	}
}

void	ft_free_solutions(int ***solutions, int len)
{
	int	cnt;

	cnt = 0;
	while (cnt <= len)
	{
		ft_printf("kommt in get longest subsequence an %i, %i", cnt, len);
		free((*solutions)[cnt]);
		(*solutions)[cnt] = NULL;
		cnt++;
	}
	free(*solutions);
	*solutions = NULL;
	
}

void get_subsequence(int *arr, int total_len_arr, t_data *data)
{
	int	**solutions;
	int	i;
	int	max_len;

	ft_printf("max len arr = %d\n", total_len_arr);
	solutions = ft_calloc(total_len_arr + 1, sizeof(solutions));
	if(!solutions)
		display_error();
	i = 0;
	while (i < total_len_arr)
	{
		solutions[i] = ft_calloc(i + 1, sizeof(**solutions));
		if (!solutions[i])
		{
			ft_free_2d((void ***)&solutions);
			display_error();
		}
		i++;
	}
	i = 1;
	max_len = 0;
	//solutions[0] = intdup(arr, 1, solutions);
	ft_memcpy(solutions[0], arr, sizeof(**solutions));
	while (i < total_len_arr)
	{
		ft_printf("i: %i\n", i);
		if (arr[i] > solutions[max_len][max_len])
		{
			ft_printf("i if: %i\n", i);
			create_new_max_list(solutions, max_len, arr, i);
			max_len++;
		}
		else
		{
			ft_printf("i else: %i\n", i);
			check_subsequence(max_len, arr[i], solutions);
		}
		i++;
		print_int_arr(solutions[max_len], max_len + 1);
		ft_printf("maxlen: %i\n\n", max_len);
	}
	ft_printf("vor if\n");
	if (data->len_sub < max_len + 1)
	{
		data->start_sub = arr[0];
		data->len_sub = max_len + 1;
		if(data->longest_sub)
		{
			free(data->longest_sub);
			data->longest_sub = intdup(solutions[max_len], max_len + 1);
			//print_int_arr(data->longest_sub, max_len);
		}
		else
			data->longest_sub = intdup(solutions[max_len], max_len + 1);
	}
	print_int_arr(data->longest_sub, max_len);
	ft_free_2d((void ***) &solutions);
	//ft_free_solutions(&solutions, max_len);
}

void	rotate_arr(int **arr, int len)
{
	int	temp;
	int	i;

	i = 1;
	temp = (*arr)[0];
	while (i < len)
	{
		(*arr)[i - 1] = (*arr)[i];
		i++;
	}
	(*arr)[len - 1] = temp;
}

void	get_longest_subsequence(t_data *data)
{
	int	*arr;
	int i;

	i = 1;
	arr = lst_to_arr(data->stack1);
	rotate_arr(&arr, data->len_list);
	data->start_sub = arr[0];
	data->longest_sub = NULL;
	while (i < data->len_list)
	{
		rotate_arr(&arr, data->len_list);
		get_subsequence(arr, data->len_list, data);
		ft_printf("i = %i\n", i);
		i++;
	}
	ft_printf("max_len: %i, start: %i\n", data->len_sub, data->start_sub);
	print_int_arr(data->longest_sub, data->len_sub);
	ft_free_1d((void**) &arr);
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
	ft_lstprint(data.stack1, 1);
	ft_lstprint(data.stack2, 2);
	get_longest_subsequence(&data);
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
	 system("leaks push_swap");
	return (0);
}
