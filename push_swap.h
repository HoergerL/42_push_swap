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


// handle_input.c

// creates data
t_content	*create_data(int nbr);
// checks the list for duplicates
int	ft_lst_dup(t_list *list, int nbr);
// converts the input to numbers, checks them and adds them to the back of the list
void	check_input(char *str[], t_data *data);
// splits the input and manages the other function calls
void	prepare_input(int argc, char *argv[], t_data *data);


//main_utils.c

// rotates the list after the elements are sorted so that the smallest element is first
void		bring_into_right_order(t_data *data);
// checks whether the list is already sorted
int			check_already_sorted(t_data *data);
// handles lists of size 3 or smaller
void		handle_short_lists(t_data *data);


// subsequence.c

// checks whether there is a better subsequence if you add val
void		check_subsequence(int max_len, int val, int **solutions);
// overwrites the old longest subsequence
void		edit_data(t_data *data, int max_len, int *arr, int **solutions);
// generates the longest subsequence based on arr
void		get_subsequence(int *arr, int total_len_arr, t_data *data);
// roates the array in case there is a longer subsequence when you start differently
void		rotate_arr(int **arr, int len);
// returns the longest subsequence and manages the other functions
void		get_longest_subsequence(t_data *data);


// subsequence_utils.c

// copies list to an array, based on which the generation of the longest subsequence will happen
int			*lst_to_arr(t_list *list);
// creates a new longest subsequence list if there is a newly found
void		create_new_max_list(int **solutions, int *max_len, int *arr, int i);
// duplicates the longest subsequence
int			*intdup(int const *src, size_t len);


//outsource_elements.c

// checks if an int has to be pushed to b
void		outsource_elements(t_content *content, int intchr);
// pushs all elemments which are not part of the longest subsequence to stack b
void		outsource_elements_not_in_sub(t_data *data);


// push_back.c

// finds the best way to rotate the stacks to push the element back
int			get_lowest_rotation(t_movement *movement, t_list *list);
// deletes all the flags saved in movement
void		truncate_flag_movements(t_list *list);
// calculates the flags for rotating in different directions and saves them in movement
void		set_flags_mvmnt(t_movement *movement, t_list *list);
// fill the results of the best rotation back into data
void		fill_data(t_movement *movement, t_list *list);
// calculates the number of rotations needed to push the element to the right place
int			calc_rot(t_data *data, int idx_src, int idx_dst, t_list *list);


// push_back_utils.c

// finds the biggest and the smallest element of stack a
// (to cover the cases where numbers are bigger than the biggest element of stack a
// or smaller than the smalles element)
void		define_biggest_smallest_el_stack1(t_data *data);
// finds the index of the element we want to rotate by value
t_list		*lst_find_el_by_value(t_list *list, int value);
// excutes the calculated rotates to bring the object on top of stack b 
// and the next higher element on top of stack a
void		ft_execute_rotates(t_data *data);
// excutes the calculated reverse rotates to bring the object on top of stack b 
// and the next higher element on top of stack a
void		ft_execute_reverse_rotates(t_data *data);


// push_back_utils2.c
// executes the rotation and the push back for the optimal element
void		push_back_optimal_element(t_data *data);
// manages functions to push back the best element
void		push_back(t_data *data);


// push_back_utils3.c

// calculates the place in stack a where the element needs to be inserted 
int			find_correct_place_for_el(t_data *data, t_list *list);
// calculates the number of operations for all elements in stack b to push back
int			calc_steps(t_data *data, t_list *list, int index);
// finds the minimal number to push back
int			calc_optimal_push_back(t_data *data);


//errors.c

// frees content
void		ft_del(void *content);
// deletes the stack pointed by list_head
void		ft_del_stack(t_list *list_head);
// displays "Error" and exits the programm
void		display_error(void);
// casts content from void * to t_content*
t_content	*ft_cast_content(void *content);


// push_swap_tester.c

// checks if the stack is sorted
void		check_sorted(t_data *data, int flag);
// executes the actual command on the stacks
void		execute_cmd(t_data *data, char *str);
// reads the next command with getnextline and executes it with execute_cmd
void		execute_cmds(t_data *data);
// checks if stack b is empty
void	check_stackb_empty(t_data *data);



//swap.c

//executes the actual swapping of the top two elements in the list
void		swap(t_list *list);
//calls swap on list b and prints "sb"
int			cmd_sb(t_data *data);
//calls swap on list a and prints "sa"
int			cmd_sa(t_data *data);
//calls swap on list a and b and prints "ss"
int			cmd_ss(t_data *data);


// rotate.c

// executes the actual rotation of the list
void		rotate(t_list **list);
// calls rotate on list a and prints "ra"
int			cmd_ra(t_data *data);
// calls rotate on list b and prints "ra"
int			cmd_rb(t_data *data);
// calls rotate on list a and b and prints "rr"
int			cmd_rr(t_data *data);


// reverse_rotate.c

// executes the actual reverse rotation of the list
void		reverse_rotate(t_list **list);
// calls reverse_rotate on list a and b and prints "rrr"
int			cmd_rrr(t_data *data);
// calls reverse_rotate on list b and prints "rrb"
int			cmd_rrb(t_data *data);
// calls reverse_rotate on list a and prints "rra"
int			cmd_rra(t_data *data);


// push.c

// executes the actual push from list_pull to list_push
void		push(t_list **list_pull, t_list **list_push);
// calls push from list b to list a and prints "pa"
int			cmd_pa(t_data *data);
// calls push from list a to list b and prints "pb"
int			cmd_pb(t_data *data);

#endif