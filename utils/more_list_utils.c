/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:45:10 by echernys          #+#    #+#             */
/*   Updated: 2025/03/07 16:38:26 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	is_sorted_and_correct_size(t_stack *head, int s)
// {
// 	if (ps_lstsize(head) != s)
// 		return (0);
// 	if (is_sorted(head))
// 		return (0);
// 	return (1);
// }

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*secondlast(t_stack *headnode)
{
	t_stack	*temp;

	if (!headnode || headnode->next == NULL)
		return (NULL);
	temp = headnode;
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

t_stack	*ps_lstlast(t_stack *headnode)
{
	t_stack	*temp;

	if (!headnode)
		return (NULL);
	temp = headnode;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	ps_lstsize(t_stack *head)
{
	int		i;
	t_stack	*temp;

	if (!head)
		return (0);
	i = 0;
	temp = head;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
