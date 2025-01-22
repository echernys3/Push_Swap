/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:15 by echernys          #+#    #+#             */
/*   Updated: 2025/01/22 16:44:14 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	index_t_stack(t_stacks **stacks, t_stack *head)
{
	t_stack	*temp;
	int		count;
	t_stack	**values;

	if (head == NULL)
		exit_error (stacks, ERR_UNK);
	temp = head;
	values = malloc(ps_stacksize(temp) * sizeof(t_stack));
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
}

t_stack	*create_node(t_stacks **stacks, char *number)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit_error(stacks, ERR_ALLOC);
	new_node -> number = ps_atoi(number, stacks);
	new_node -> next = NULL;
	return (new_node);
}

void	ps_stackadd_back(t_stack *stack, t_stack *newnode)
{
	t_stack	*current;

	current = stack;
	if (!newnode)
		return ;
	if (!(stack))
		stack = newnode;
	else
	{
		while (current -> next != NULL)
			current = current -> next;
		current->next = newnode;
	}
}
