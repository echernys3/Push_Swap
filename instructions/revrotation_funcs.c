/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotation_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:38:00 by echernys          #+#    #+#             */
/*   Updated: 2025/03/06 15:38:00 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = ps_lstlast(*stack_a);
	temp = secondlast(*stack_a);
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
	temp = NULL;
	last = NULL;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = ps_lstlast(*stack_b);
	temp = secondlast(*stack_b);
	temp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
	temp = NULL;
	last = NULL;
}

static void	copy_rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = ps_lstlast(*stack_a);
	temp = secondlast(*stack_a);
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	temp = NULL;
	last = NULL;
}

static void	copy_rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = ps_lstlast(*stack_b);
	temp = secondlast(*stack_b);
	temp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	temp = NULL;
	last = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	copy_rra(stack_a);
	copy_rrb(stack_b);
	ft_printf("rrr\n");
}
