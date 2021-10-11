/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 18:24:56 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/11 15:08:36 by lhoerger         ###   ########.fr       */
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

#define ROTATE 1
#define REVERSE_ROTATE 2
#define RA_RRB 3
#define RB_RRA 4

typedef struct s_movement
{
	int	rbs;
	int	rrbs;
	int	ras;
	int	rras;
	int	total_reverse;
	int	total;
	int	ra_rrb;
	int	rb_rra;
}					t_movement;
typedef struct s_content
{
	int		value;
	int		flag_longest_sub;
	int		flag_movement_ra;
	int		flag_movement_rb;
	int		flag_movement_rr;
	int		flag_movement_rrb;
	int		flag_movement_rra;
	int		flag_movement_rrr;
	int		flag_movement;
}					t_content;

typedef struct s_data
{
	t_list	*stack1;
	t_list	*stack2;
	int		len_list;
	int		len_sub;
	int		start_sub;
	int		*longest_sub;
	int		biggest_el_stack1;
	int		smallest_el_stack1;
	int		flag_movement;
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
void	print_stacks(t_data *data);
#endif