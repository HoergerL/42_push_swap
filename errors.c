/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:25:10 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/02 18:25:11 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_del(void *content)
{
	ft_free_1d(content);
}

void	ft_del_stack(t_list *list_head)
{
	if (list_head == NULL)
		return ;
	ft_lstclear(&list_head, ft_del);
}

void	display_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
