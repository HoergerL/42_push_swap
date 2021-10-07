/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:24:56 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/07 16:44:22 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_content
{
	int		value;
}					t_content;

typedef struct s_data
{
	t_list	*stack1;
	t_list	*stack2;
	int		len_list;
}					t_data;

void		prepare_input(int argc, char *argv[], t_data *data);
void		ft_del_stack(t_list *list_head);
void		display_error(void);
t_content	*ft_cast_content(void *content);
int			cmd_sb(t_data *data);
int			cmd_sa(t_data *data);
int			cmd_ss(t_data *data);
int			cmd_pa(t_data *data);
int			cmd_pb(t_data *data);
int			cmd_ra(t_data *data);
int			cmd_rb(t_data *data);
int			cmd_rr(t_data *data);
int			cmd_rrr(t_data *data);
int			cmd_rrb(t_data *data);
int			cmd_rra(t_data *data);
void		ft_lstprint(t_list *list, int nr);
#endif