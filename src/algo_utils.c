/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:46:21 by echernys          #+#    #+#             */
/*   Updated: 2025/01/22 14:05:16 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*secondlast(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL || stack->next == NULL)
		return (NULL);
	temp = stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

int	b_sorted(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp && temp->next)
	{
		if (temp->index < temp->next->index)
			return (i);
		i++;
		temp = temp -> next;
	}
	return (0);
}

void	sort_3(t_stack *stack)
{
	if (stack->index > stack->next->index)
	{
		
	}
}
