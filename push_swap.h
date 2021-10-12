/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:24:56 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/12 14:14:53 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define ROTATE 1
# define REVERSE_ROTATE 2
# define RA_RRB 3
# define RB_RRA 4

typedef struct s_movement
{
	int	rbs;
	int	rrbs;
	int	ras;
	int	rras;
	int	tot_rev;
	int	total;
	int	ra_rrb;
	int	rb_rra;
}					t_movement;
typedef struct s_content
{
	int		value;
	int		flag_longest_sub;
	int		flag_mvmnt_ra;
	int		flag_mvmnt_rb;
	int		flag_mvmnt_rr;
	int		flag_mvmnt_rrb;
	int		flag_mvmnt_rra;
	int		flag_mvmnt_rrr;
	int		flag_mvmnt;
}					t_content;

typedef struct s_data
{
	t_list	*stack1;
	t_list	*stack2;
	int		len_list;
	int		len_sub;
	int		start_sub;
	int		*longest_sub;
	int		big_el_1;
	int		smal_el_1;
	int		flag_mvmnt;
	int		nbr_to_move;
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
void		get_longest_subsequence(t_data *data);
int			*lst_to_arr(t_list *list);
void		create_new_max_list(int **solutions, int *max_len, int *arr, int i);
int			*intdup(int const *src, size_t len);
void		print_int_arr(int *arr, int len);
void		outsource_elements_not_in_sub(t_data *data);
int			calc_optimal_push_back(t_data *data);
int			calc_steps(t_data *data, t_list *list, int index);
int			find_correct_place_for_el(t_data *data, t_list *list);
int			calc_rot(t_data *data, int idx_src, int idx_dst, t_list *list);
void		fill_data(t_data *data, t_movement *movement, t_list *list);
void		truncate_flag_movements(t_data *data, t_list *list);
int			get_lowest_rotation(t_movement *movement, t_list *list);
void		define_biggest_smallest_el_stack1(t_data *data);
t_list		*lst_find_el_by_value(t_list *list, int value);
void		push_back_optimal_element(t_data *data);
void		push_back(t_data *data);
void		bring_into_right_order(t_data *data);
int			check_already_sorted(t_data *data);
void		handle_short_lists(t_data *data);
void		ft_execute_reverse_rotates(t_data *data);
void		ft_execute_rotates(t_data *data);
//push_back_utils3.c
int			calc_optimal_push_back(t_data *data);
int			calc_steps(t_data *data, t_list *list, int index);
int			find_correct_place_for_el(t_data *data, t_list *list);
//void		print_stacks(t_data *data);
#endif