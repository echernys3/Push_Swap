/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:15 by echernys          #+#    #+#             */
/*   Updated: 2025/01/21 14:34:55 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static t_stack	**sort_values(t_stack **values, int count)
{
	t_stack	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (values[i]->number > values[j]->number)
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (values);
}

static t_stack	**update_index(t_stack **values, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		values[i]->index = i + 1;
		i++;
	}
	return (values);
}

t_stack	**index_t_stack(t_stacks **stacks, t_stack *head)
{
	t_stack	*temp;
	int		count;
	t_stack	**values;

	if (head == NULL)
		return (NULL);
	temp = head;
	values = malloc(ft_lstsize(temp) * sizeof(*t_stack));
	if (!values)
		exit_error(stacks, ERR_ALLOC);
	temp = head;
	count = 0;
	while (temp != NULL)
	{
		values[count] = temp;
		count++;
		temp = temp->next;
	}
	values = sort_values(values, count);
	update_index(values, count);
	return (head);
}

t_stack	*create_node(t_stacks **stacks, char *number)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit_error(stacks, ERR_ALLOC);
	new_node -> number = ps_atoi(number);
	new_node -> next = NULL;
	return (new_node);
}
