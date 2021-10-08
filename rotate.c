#include "push_swap.h"

void	rotate(t_list **list)
{
	t_list	*temp_list;

	temp_list = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, temp_list);
}

int	cmd_ra(t_data *data)
{
	if (data->stack1 == NULL)
		return (0);
	rotate(&data->stack1);
	write(1, "ra\n", 3);
	return (1);
}

int	cmd_rb(t_data *data)
{
	if (data->stack2 == NULL)
		return (0);
	rotate(&data->stack2);
	write(1, "rb\n", 3);
	return (1);
}

int	cmd_rr(t_data *data)
{
	if (data->stack1 == NULL || data->stack2 == NULL)
		return (0);
	cmd_ra(data);
	cmd_rb(data);
	write(1, "rr\n", 3);
	return (1);
}
