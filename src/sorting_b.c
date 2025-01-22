/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:39:56 by echernys          #+#    #+#             */
/*   Updated: 2025/01/22 15:43:11 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stack_b, t_stacks **stacks);
void	last_not_sorted(t_stack *stack_b, t_stacks **stacks);
void	swap(t_stack *stack_b, t_stacks **stacks);

void	sort_in_b(t_stack *stack_b, t_stacks **stacks)
{
	if (stack_b->next == NULL || b_sorted(&stack_b) || (*stacks)->size_b == 1)
		return ;
	if ((*stacks)->size_b == 2 && stack_b->index < stack_b->next->index)
		sb(&stack_b, stacks);
	if ((*stacks)->size_b == 3)
	{
		if (stack_b->index < stack_b->next->index)
		{
			if (stack_b->index < stack_b->next->next->index)
				rb(stacks);
			else
				sb(&stack_b, stacks);
		}
		else if (stack_b->next->index < stack_b->next->next->index)
		{
			rb(stacks);
			sb(&stack_b, stacks);
			rrb(stacks);
		}
	}
	if (stack_b->index < (ps_lstlast(stack_b))->index)
		rotate(stack_b, stacks);
	if (stack_b->index < stack_b->next->index)
		swap(stack_b, stacks);
}

void	rotate(t_stack *stack_b, t_stacks **stacks)
{
	if ((stack_b->index > (secondlast(stack_b))->index))
		last_not_sorted(stack_b, stacks);
	else
	{
		if ((*stacks)->stack_a->index > (*stacks)->stack_a->next->index
			&& (*stacks)->stack_a->next->index
			< ps_lstlast((*stacks)->stack_a)->index)
			rr(stacks);
		else
			rb(stacks);
	}
}

void	last_not_sorted(t_stack *stack_b, t_stacks **stacks)
{
	int	i;

	i = 2;
	while (i--)
	{
		if ((*stacks)->stack_a->index
			> ps_lstlast((*stacks)->stack_a)->index
			&& (*stacks)->stack_a->next->index
			> ps_lstlast((*stacks)->stack_a)->index)
			rrr(stacks);
		else
			rrb(stacks);
	}
	sb(&stack_b, stacks);
	rb(stacks);
	sb(&stack_b, stacks);
	rb(stacks);
	rb(stacks);
}

void	swap(t_stack *stack_b, t_stacks **stacks)
{
	if ((*stacks)->stack_a->index > (*stacks)->stack_a->next->index)
		ss(*stacks);
	else
		sb(&stack_b, stacks);
}
