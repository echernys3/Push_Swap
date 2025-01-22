/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:39:56 by echernys          #+#    #+#             */
/*   Updated: 2025/01/22 12:04:49 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stack_b, t_stacks **stacks);
void	last_not_sorted(t_stack *stack_b, t_stacks **stacks);
void	swap(t_stack *stack_b, t_stacks **stacks);

void	sort_in_b(t_stack *stack_b, t_stacks **stacks)
{
	if (stack_b->next == NULL || b_sorted(stacks) || stack_b->size == 1)
		return ;
	if (stack_b->size == 2 && stack_b->index < stack_b->next->index)
		sb(stacks);
	if (stack->size == 3)
		//ACOPIERLECODE DE SORT 3 MAIS A L'INVERS;
	if (stack_b->index < (ft_lstlast(stack_b))->index)
		rotate(stack_b, stacks);
	if (stack_b->index < stack_b->next->index)
		swap(stack_b, stacks);
}

void	rotate(t_stack *stack_b, t_stacks **stacks)
{
	if ((stack_b->index > secondlast(stack_b))->index)
		last_not_sorted(stack_b, stacks);
	else
	{
		if ((*stacks)->stack_a->index > (*stacks)->stack_a->next->index
			&& (*stacks)->stack_a->next->index
			< ft_lstlast((*stacks)->stack_a)->index)
			rr(stacks);
		else
			rb(stacks);
	}
}

void	last_not_sorted(t_stack *stack_b, t_stacks **stacks)
{
	while (2--)
	{
		if ((*stacks)->stack_a->index
			> ft_lstlast((*stacks)->stack_a)->index
			&& (*stacks)->stack_a->next->index
			> ft_lstlast((*stacks)->stack_a)->index)
			rrr(stacks);
		else
			rrb(stacks);
	}
	sb(stacks);
	rb(stacks);
	sb(stacks);
	rb(stacks);
	rb(stacks);
}

void	swap(t_stack *stack_b, t_stacks **stacks)
{
	if ((*stacks)->stack_a->index > (*stacks)->stack_a->next->index)
		ss(stacks, stacks);
	else
		sb(stacks, stacks);
}
