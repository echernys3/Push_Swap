/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:24:44 by echernys          #+#    #+#             */
/*   Updated: 2025/01/21 15:57:15 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stacks **stacks)
{
	t_stack	*temp;

	if ((*stacks)->stack_b == NULL)
		return ;
	temp = ((*stacks)->stack_b);
	(*stacks)->stack_b = (*stacks)->stack_b->next;
	temp->next = (*stacks)->stack_a;
	(*stacks)->stack_a = temp;
	(*stacks)->size_a++;
	(*stacks)->size_b--;
	(*stacks)->operations++;
	ft_printf("pa\n");
}

void	pb(t_stacks **stacks)
{
	t_stack	*temp;

	if ((*stacks)->stack_a == NULL)
		return ;
	temp = ((*stacks)->stack_a);
	(*stacks)->stack_a = (*stacks)->stack_a->next;
	temp->next = (*stacks)->stack_b;
	(*stacks)->stack_b = temp;
	(*stacks)->size_b++;
	(*stacks)->size_a--;
	(*stacks)->operations++;
	ft_printf("pb\n");
}
