/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:19:58 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/11 17:20:03 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_subsequence(int max_len, int val, int **solutions)
{
	int	j;

	j = max_len;
	while (j >= 0)
	{
		if (val > solutions[j][j] && val <= solutions[j + 1][j + 1])
		{
			free(solutions[j + 1]);
			solutions[j + 1] = intdup(solutions[j], j + 2);
			solutions[j + 1][j + 1] = val;
		}
		if (val < solutions[j][j] && ((j == 0) || (val > solutions[j][j - 1])))
			solutions[j][j] = val;
		j--;
	}
}

void	edit_data(t_data *data, int max_len, int *arr, int **solutions)
{
	if (data->len_sub < max_len + 1)
	{
		data->start_sub = arr[0];
		data->len_sub = max_len + 1;
		if (data->longest_sub)
		{
			free(data->longest_sub);
			data->longest_sub = intdup(solutions[max_len], max_len + 1);
		}
		else
			data->longest_sub = intdup(solutions[max_len], max_len + 1);
	}
}

void	get_subsequence(int *arr, int total_len_arr, t_data *data)
{
	int	**solutions;
	int	i;
	int	max_len;

	solutions = ft_calloc(total_len_arr + 1, sizeof(solutions));
	if (!solutions)
		display_error();
	i = 1;
	max_len = 0;
	solutions[0] = intdup(arr, 1);
	while (i < total_len_arr)
	{
		if (arr[i] > solutions[max_len][max_len])
			create_new_max_list(solutions, &max_len, arr, i);
		else
		{
			check_subsequence(max_len, arr[i], solutions);
		}
		i++;
	}
	edit_data(data, max_len, arr, solutions);
	ft_free_2d((void ***) &solutions);
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
	int	i;

	i = 1;
	arr = lst_to_arr(data->stack1);
	rotate_arr(&arr, data->len_list);
	data->start_sub = arr[0];
	data->longest_sub = NULL;
	while (i < data->len_list)
	{
		rotate_arr(&arr, data->len_list);
		get_subsequence(arr, data->len_list, data);
		i++;
	}
	ft_free_1d((void **) &arr);
}
