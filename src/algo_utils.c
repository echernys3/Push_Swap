/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:46:21 by echernys          #+#    #+#             */
/*   Updated: 2024/12/16 15:31:04 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_for_min(t_stack *stack, t_stacks **stacks)
{
	if (stack->index == 1)
	{
		pb(stacks);
	}
	if (ft_lstlast(stack)->index == 1)
	{
		rrr(stacks);
		pb(stacks);
	}
	
}
