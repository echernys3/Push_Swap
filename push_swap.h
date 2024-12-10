/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:45 by echernys          #+#    #+#             */
/*   Updated: 2024/12/05 18:06:39 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack{

	int	number;
	int index;
	struct s_stack *next;
	
} t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	size_a;
	int	size_b;
	int	operations;
} t_stacks;

t_stack	**index_t_stack(t_stack *head);
t_stack	*create_node(int number);

void	sa(t_stack **head, t_stacks **stacks);
void	sb(t_stack **head, t_stacks **stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks **stacks);
void	pb(t_stacks **stacks);
void	ra(t_stacks **stacks);
void	rb(t_stacks **stacks);
void	rr(t_stacks **stacks);
t_stack	*secondlast(t_stack *stack);
void	rra(t_stacks **stacks);
void	rrb(t_stacks **stacks);
void	rrr(t_stacks **stacks);

#endif