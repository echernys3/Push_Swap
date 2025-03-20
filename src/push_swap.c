/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:05:12 by echernys          #+#    #+#             */
/*   Updated: 2025/03/17 14:28:53 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third)
		rra(stack_a);
}

static int	find_smallest(t_stack *stack_a)
{
	t_stack	*smallest;
	int		pos;
	int		i;

	smallest = stack_a;
	pos = 0;
	i = 0;
	while (stack_a)
	{
		if (stack_a->index < smallest->index)
		{
			smallest = stack_a;
			pos = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (pos);
}

static void	move_smallest(t_stack **stack_a, int pos, int size)
{
	int		i;
	t_stack	*temp;

	temp = *stack_a;
	i = 0;
	while (temp)
	{
		if (i == pos)
			break ;
		temp = temp->next;
		i++;
	}
	while ((*stack_a) != temp)
	{
		if (pos < size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pos;

	while (size-- > 3)
	{
		pos = find_smallest(*stack_a);
		move_smallest(stack_a, pos, size);
		pb(stack_a, stack_b);
	}
}

// void	ps_algo(t_stack **stack_a, t_stack **stack_b, int size, int pivot)
// {
// 	while (size > pivot)
// 	{
// 		if ((*stack_a)->index < pivot)
// 		{
// 			pb(stack_a, stack_b);
// 			size--;
// 		}	
// 		else
// 			ra(stack_a);
// 	}
// }

void	push_swap(t_stack **stack_a, int size)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (is_sorted(*stack_a))
	{
		ps_freer(NULL, *stack_a, NULL);
		return ;
	}
	if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 15)
	{
		sort_small(stack_a, &stack_b, size);
		sort_three(stack_a);
	}
	else
		radix_sort(stack_a, &stack_b, size);
	while (stack_b)
		pa(stack_a, &stack_b);
	ps_freer(NULL, *stack_a, stack_b);
}
