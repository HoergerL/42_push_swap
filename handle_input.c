/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:25:00 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/11 16:40:00 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content	*create_data(int nbr)
{
	t_content	*content;

	content = malloc(sizeof(t_content));
	if (!content)
		display_error();
	ft_bzero(content, sizeof(t_content));
	content->value = nbr;
	content->flag_longest_sub = 0;
	return (content);
}

int	ft_lst_dup(t_list *list, int nbr)
{
	t_list		*curr_el;
	t_content	*content;

	while (list)
	{
		content = ft_cast_content(list->content);
		if (content->value == nbr)
			display_error();
		list = (list)->next;
	}
	return (1);
}

void	check_input(char *str[], t_data *data)
{
	int				i;
	long long int	nbr;
	t_list			*new_el;

	i = 0;
	while (str[i] != NULL)
	{
		if (ft_check_nbr(str[i]))
		{
			nbr = ft_atoll(str[i]);
			if (nbr < INT_MAX && nbr > INT_MIN && ft_lst_dup(data->stack1, nbr))
			{
				new_el = ft_lstnew(create_data(nbr));
				if (new_el == 0)
					display_error();
				ft_lstadd_back(&data->stack1, new_el);
			}
			else
				display_error();
		}
		else
			display_error();
		i++;
	}
}

void	prepare_input(int argc, char *argv[], t_data *data)
{
	int		i;
	char	**split_res;

	i = 1;
	if (argc < 2)
		exit(0);
	while (argv[i] != NULL)
	{
		split_res = ft_split(argv[i], ' ');
		if (split_res == 0)
			display_error();
		check_input(split_res, data);
		ft_free_2d((void ***) &split_res);
		i++;
	}
	if (ft_lstsize(data->stack1) < 2)
		exit(1);
}
