/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:31:28 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/11 17:19:33 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	create_new_max_list(int **solutions, int *max_len, int *arr, int i)
{
	solutions[(*max_len) + 1] = intdup(solutions[(*max_len)], (*max_len) + 2);
	solutions[(*max_len) + 1][(*max_len) + 1] = arr[i];
	(*max_len) = (*max_len) + 1;
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
