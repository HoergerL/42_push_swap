/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:29:15 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/07 16:49:10 by lhoerger         ###   ########.fr       */
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

int * intdup(int const * src, size_t len)
{
	int * p = malloc(len * sizeof(int));
	if(!p)
		display_error();
	ft_memcpy(p, src, len * sizeof(int)); //wir kopieren 1 zu viel
	return p;
}

void	print_int_arr(int *arr, int len)
{
	int k;

	k = 0;
	while(k < len)
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
	int i;

	len = ft_lstsize(list);
	//ft_printf("len: %i\n", len);
	i = 0;
	arr = malloc(sizeof(int) * len);
	while (list)
	{
		arr[i] = ft_cast_content(list->content)->value;
		list = list->next;
		i++;
	}
	//print_int_arr(arr, len);
	return arr;
}

void	create_new_max_list(int ***solutions, int *max_len, int *arr, int i)
{
	(*solutions)[(*max_len) + 1] = intdup((*solutions)[(*max_len)], (*max_len) + 2);
	(*solutions)[(*max_len) + 1][(*max_len) + 1] = arr[i];
	(*max_len) = (*max_len) + 1;
}

void	check_subsequence(int max_len, int val, int ***solutions)
{
	int	j;
	j = max_len;
	while (j >= 0)
	{
		if(val > (*solutions)[j][j] && val <= (*solutions)[j + 1][j + 1])
		{
			free((*solutions)[j + 1]);
				(*solutions)[j + 1] = intdup((*solutions)[j], j + 2);
				(*solutions)[j + 1][j + 1] = val;
		}
		if(val < (*solutions)[j][j] && ((j == 0) || (val > (*solutions)[j][j - 1])))
			(*solutions)[j][j] = val;
		j--;
	}
}

int	calc_subsequence(int *arr, int total_len_arr)
{
	int **solutions;
	int i;
	int max_len;
	
	solutions = malloc(total_len_arr * sizeof(int));
	if(!solutions)
		display_error();
	i = 1;
	max_len = 0;
	solutions[0] = intdup(arr, 1);	
	while(i < total_len_arr)
	{
		if (arr[i] > solutions[max_len][max_len])
		{
			create_new_max_list(&solutions, &max_len, arr, i);
		}
		else
			check_subsequence(max_len, arr[i], &solutions);
		i++;
	}
	//print_int_arr(solutions[max_len], max_len + 1);
	return (max_len + 1);
}

int	*get_subsequence(int *arr, int total_len_arr)
{
	int **solutions;
	int i;
	int max_len;
	
	solutions = malloc(total_len_arr * sizeof(int));
	if(!solutions)
		display_error();
	i = 1;
	max_len = 0;
	solutions[0] = intdup(arr, 1);	
	while(i < total_len_arr)
	{
		if (arr[i] > solutions[max_len][max_len])
		{
			create_new_max_list(&solutions, &max_len, arr, i);
		}
		else
			check_subsequence(max_len, arr[i], &solutions);
		i++;
	}
	print_int_arr(solutions[max_len], max_len + 1);
	return (solutions[max_len]);
}

void rotate_arr(int **arr, int len)
{
	int temp;
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

void get_longest_subsequence(t_list *list)
{
	int	*arr;
	int max;
	int start;
	int i;
	int temp;

	i = 1;
	arr = lst_to_arr(list);
	rotate_arr(&arr, ft_lstsize(list));
	start = arr[0];
	max = calc_subsequence(arr, ft_lstsize(list));
	while (i < ft_lstsize(list))
	{
		rotate_arr(&arr, ft_lstsize(list));
		temp = calc_subsequence(arr, ft_lstsize(list));
		if (temp > max)
		{
			max = temp;
			start = arr[0];
		}
		i++;
	}
	ft_printf("max_len: %i, start: %i\n", max, start);
	while (arr[0] != start)
		rotate_arr(&arr, ft_lstsize(list));
	arr = get_subsequence(arr, ft_lstsize(list));
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
	get_longest_subsequence(data.stack1);
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
