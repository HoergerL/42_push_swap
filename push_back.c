/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:35:28 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/12 10:08:04 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lowest_rotation(t_movement *movement, t_list *list)
{
	if (movement->tot_rev <= movement->total && movement->tot_rev
		<= movement->ra_rrb && movement->tot_rev <= movement->rb_rra)
	{
		ft_cast_content(list->content)->flag_mvmnt = REVERSE_ROTATE;
		return (movement->tot_rev);
	}
	if (movement->total <= movement->tot_rev && movement->total
		<= movement->ra_rrb && movement->total <= movement->rb_rra)
	{
		ft_cast_content(list->content)->flag_mvmnt = ROTATE;
		return (movement->total);
	}
	if (movement->ra_rrb <= movement->tot_rev && movement->ra_rrb
		<= movement->total && movement->ra_rrb <= movement->rb_rra)
	{
		ft_cast_content(list->content)->flag_mvmnt = RA_RRB;
		return (movement->ra_rrb);
	}
	else
	{
		ft_cast_content(list->content)->flag_mvmnt = RB_RRA;
		return (movement->rb_rra);
	}
}

void	truncate_flag_movements(t_data *data, t_list *list)
{
	ft_cast_content(list->content)->flag_mvmnt_ra = 0;
	ft_cast_content(list->content)->flag_mvmnt_rb = 0;
	ft_cast_content(list->content)->flag_mvmnt_rr = 0;
	ft_cast_content(list->content)->flag_mvmnt_rra = 0;
	ft_cast_content(list->content)->flag_mvmnt_rrb = 0;
	ft_cast_content(list->content)->flag_mvmnt_rrr = 0;
}

void	set_flags_mvmnt(t_data *data, t_movement *movement, t_list *list)
{
	t_content	*content;

	content = ft_cast_content(list->content);
	if (content->flag_mvmnt == ROTATE)
	{
		if (movement->rbs > movement->ras)
			content->flag_mvmnt_rr = movement->ras;
		else
			content->flag_mvmnt_rr = movement->rbs;
		content->flag_mvmnt_ra = movement->ras - content->flag_mvmnt_rr;
		content->flag_mvmnt_rb = movement->rbs - content->flag_mvmnt_rr;
	}
	else if (content->flag_mvmnt == REVERSE_ROTATE)
	{
		if (movement->rrbs > movement->rras)
			content->flag_mvmnt_rrr = movement->rras;
		else
			content->flag_mvmnt_rrr = movement->rrbs;
		content->flag_mvmnt_rra = movement->rras - content->flag_mvmnt_rrr;
		content->flag_mvmnt_rrb = movement->rrbs - content->flag_mvmnt_rrr;
	}
}

void	fill_data(t_data *data, t_movement *movement, t_list *list)
{
	t_content	*content;

	content = ft_cast_content(list->content);
	set_flags_mvmnt(data, movement, list);
	if (content->flag_mvmnt == RA_RRB)
	{
		content->flag_mvmnt_ra = movement->ras;
		content->flag_mvmnt_rrb = movement->rrbs;
	}
	else if (content->flag_mvmnt == RB_RRA)
	{
		content->flag_mvmnt_rra = movement->rras;
		content->flag_mvmnt_rb = movement->rbs;
	}
}

int	calc_rot(t_data *data, int idx_src, int idx_dst, t_list *list)
{
	t_movement	movement;
	int			lowest;

	ft_bzero(&movement, sizeof(t_movement));
	truncate_flag_movements(data, list);
	movement.rbs = idx_src;
	movement.rrbs = ft_lstsize(data->stack2) - idx_src;
	if (ft_lstsize(data->stack2) == 1)
		movement.rrbs = 0;
	movement.ras = idx_dst;
	movement.rras = ft_lstsize(data->stack1) - idx_dst;
	if (movement.rrbs > movement.rras)
		movement.tot_rev = movement.rrbs;
	else
		movement.tot_rev = movement.rras;
	if (movement.rbs > movement.ras)
		movement.total = movement.rbs;
	else
		movement.total = movement.ras;
	movement.ra_rrb = movement.ras + movement.rrbs;
	movement.rb_rra = movement.rbs + movement.rras;
	lowest = get_lowest_rotation(&movement, list);
	fill_data(data, &movement, list);
	return (lowest);
}
