#include "push_swap.h"

void	swap(t_list *list)
{
	t_content	*content_temp;

	if (list == NULL || list->next == NULL)
		return ;
	content_temp = list->content;
	list->content = (void *) list->next->content;
	list->next->content = (void *) content_temp;
}

int	cmd_sa(t_data *data)
{
	if (data->stack1 == NULL || data->stack1->next == NULL)
		return (0);
	swap(data->stack1);
	write(1, "sa\n", 3);
	return (1);
}

int	cmd_sb(t_data *data)
{
	if (data->stack2 == NULL || data->stack2->next == NULL)
		return (0);
	swap(data->stack2);
	write(1, "sb\n", 3);
	return (1);
}

int	cmd_ss(t_data *data)
{
	if (data->stack2 == NULL || data->stack2->next == NULL
	|| data->stack1 == NULL || data->stack1->next == NULL)
		return (0);
	swap(data->stack2);
	swap(data->stack1);
	write(1, "ss\n", 3);
	return (1);
}
