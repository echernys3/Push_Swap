/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:38:08 by echernys          #+#    #+#             */
/*   Updated: 2025/03/10 17:26:07 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = ps_lstlast(*stack_a);
	temp = (*stack_a)->next;
	last->next = *stack_a;
	(*stack_a)->next = NULL;
	*stack_a = temp;
	ft_printf("ra\n");
	temp = NULL;
	last = NULL;
}

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = ps_lstlast(*stack_b);
	temp = (*stack_b)->next;
	last->next = *stack_b;
	(*stack_b)->next = NULL;
	*stack_b = temp;
	ft_printf("rb\n");
	temp = NULL;
	last = NULL;
}

static void	copy_ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = ps_lstlast(*stack_a);
	temp = (*stack_a)->next;
	last->next = *stack_a;
	(*stack_a)->next = NULL;
	*stack_a = temp;
	temp = NULL;
	last = NULL;
}

static void	copy_rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = ps_lstlast(*stack_b);
	temp = (*stack_b)->next;
	last->next = *stack_b;
	(*stack_b)->next = NULL;
	*stack_b = temp;
	temp = NULL;
	last = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	copy_ra(stack_a);
	copy_rb(stack_b);
	ft_printf("rr\n");
}
