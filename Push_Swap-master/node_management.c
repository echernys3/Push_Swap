/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:15 by echernys          #+#    #+#             */
/*   Updated: 2024/12/05 15:39:22 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_stack	**sort_values(t_stack **values, int count)
{
	t_stack *temp;
	int	i;
	int	j;

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

t_stack	**index_t_stack(t_stack *head)
{
	t_stack *temp;
	int count;
	t_stack **values;

	if (head == NULL)
		return (NULL);
	temp = head;
	values = malloc(ft_lstsize(temp) * sizeof(t_stack*));
	if (!values)
		return ;
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


t_stack	*create_node(int number)
{
	t_stack *new_node = malloc(sizeof(t_stack));
	new_node -> number = number;
	new_node -> next = NULL;
	return (new_node);
}