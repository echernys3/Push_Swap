/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotation_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:36 by echernys          #+#    #+#             */
/*   Updated: 2024/12/10 13:29:36 by echernys         ###   ########.fr       */
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

void	rra(t_stacks **stacks)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*stacks)->stack_a == NULL || (*stacks)->stack_a->next == NULL)
		return ;
	last = ft_lstlast((*stacks)->stack_a);
	temp = secondlast((*stacks)->stack_a);
	temp->next = NULL;
	last->next = (*stacks)->stack_a;
	(*stacks)->stack_a = last;
	(*stacks)->operations++;
	ft_printf("rra\n");
}

void	rrb(t_stacks **stacks)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*stacks)->stack_b == NULL || (*stacks)->stack_b->next == NULL)
		return ;
	last = ft_lstlast((*stacks)->stack_b);
	temp = secondlast((*stacks)->stack_b);
	temp->next = NULL;
	last->next = (*stacks)->stack_b;
	(*stacks)->stack_b = last;
	(*stacks)->operations++;
	ft_printf("rrb\n");
}