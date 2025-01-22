/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:45 by echernys          #+#    #+#             */
/*   Updated: 2025/01/22 14:00:00 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack{

	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;
	int		size_b;
	int		operations;
}	t_stacks;

//Utils
t_stack	*secondlast(t_stack *stack);

//Working with A stack
void	first_is_smol(t_stack *stack_a, t_stacks **stacks);
void	last_is_smol(t_stack *last, t_stacks **stacks);
void	sort(t_stack *stack_a, t_stacks **stacks);

//Sorting in B stack
void	rotate(t_stack *stack_b, t_stacks **stacks);
void	last_not_sorted(t_stack *stack_b, t_stacks **stacks);
void	swap(t_stack *stack_b, t_stacks **stacks);
void	sort_in_b(t_stack *stack_b, t_stacks **stacks);

//Instructions
void	sa(t_stack **head, t_stacks **stacks);
void	sb(t_stack **head, t_stacks **stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks **stacks);
void	pb(t_stacks **stacks);
void	ra(t_stacks **stacks);
void	rb(t_stacks **stacks);
void	rr(t_stacks **stacks);
void	rra(t_stacks **stacks);
void	rrb(t_stacks **stacks);
void	rrr(t_stacks **stacks);

//Errors and exit
void	print_error(int errnum);
void	exit_error(t_stacks **stacks, int errnum);

#endif