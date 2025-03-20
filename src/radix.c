/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:16:20 by echernys          #+#    #+#             */
/*   Updated: 2025/03/10 17:46:05 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_to_a(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	i;

	while (*stack_b && ((*stack_b)->index & bit) == bit)
		pa(stack_a, stack_b);
	if (*stack_b)
	{
		i = (*stack_b)->index;
		rb(stack_b);
		while (*stack_b && (*stack_b)->index != i)
		{
			if (*stack_b && ((*stack_b)->index & bit) == bit)
				pa(stack_a, stack_b);
			else if (*stack_b)
				rb(stack_b);
		}
	}
}

void	a_to_b(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int	i;

	while (*stack_a && ((*stack_a)->index & bit) == 0)
		pb(stack_a, stack_b);
	if (*stack_a)
	{
		i = (*stack_a)->index;
		ra(stack_a);
		while (*stack_a && (*stack_a)->index != i)
		{
			if (*stack_a && ((*stack_a)->index & bit) == 0)
				pb(stack_a, stack_b);
			else if (*stack_a)
				ra(stack_a);
		}
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	bit;

	bit = 1;
	while (bit < size)
	{
		if (*stack_b)
			b_to_a(stack_a, stack_b, bit);
		if (*stack_a)
			a_to_b(stack_a, stack_b, bit);
		bit <<= 1;
	}
}
