#include "push_swap.h"

void	push(t_list **list_pull, t_list **list_push)
{
	t_list	*list_temp;

	list_temp = (*list_pull);
	 (*list_pull) = (*list_pull)->next;
	ft_lstadd_front(list_push, list_temp);
}

int	cmd_pa(t_data *data)
{
	if (data->stack2 == NULL)
		return (0);
	push(&data->stack2, &data->stack1);
	write(1, "pa\n", 3);
	return (1);
}

int	cmd_pb(t_data *data)
{
	if (data->stack1 == NULL)
		return (0);
	push(&data->stack1, &data->stack2);
	write(1, "pb\n", 3);
	return (1);
}
