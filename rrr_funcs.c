/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:29:46 by echernys          #+#    #+#             */
/*   Updated: 2024/12/10 13:29:46 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_rra(t_stacks **stacks)
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
}

static void	copy_rrb(t_stacks **stacks)
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
}

void	rrr(t_stacks **stacks)
{
	copy_rra(stacks);
	copy_rrb(stacks);
	(*stacks)->operations++;
	ft_printf("rrr\n");
}