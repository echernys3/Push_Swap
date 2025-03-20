/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:58:29 by echernys          #+#    #+#             */
/*   Updated: 2025/03/17 16:11:41 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/Printf/ft_printf.h"
# include "../libft/Libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

// Split functions
int		ps_count_size(char *str, char c);
void	split_freer(char **tab, int size);
char	**ps_split_nums(char *str, char c, int size);

// Utils to manipulate args data and verify it
int		*int_array_no_split(char **str, int size);
int		*int_array(char **str, int size);
void	check_doubles(int *nums, int size);

// Indexation
void	ps_get_index(t_stack **head, int size, int *nums);

// List utils
void	ps_lstaddfront(t_stack **head, t_stack *newnode);
void	ps_lstaddback(t_stack **head, t_stack *newnode);
t_stack	*create_lst(int *nums, int size);
void	ps_clearlst(t_stack **head);
t_stack	*secondlast(t_stack *headnode);
t_stack	*ps_lstlast(t_stack *headnode);
int		is_sorted(t_stack *stack);
int		ps_lstsize(t_stack *head);
// int	is_sorted_and_correct_size(t_stack *head, int s):

// Push-swap + instructions
void	push_swap(t_stack **stack_a, int size);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **head);
void	sb(t_stack **head);
void	ss(t_stack **stack_a, t_stack **stack_b);

// Radix
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

// Quick-sort
// void	quick_sort(t_stack **stack_a, t_stack **stack_b, int size_a);

// On exit
void	exit_on_split(int *nums, char **temp, int size);
void	ps_freer(int *nums, t_stack *stack_a, t_stack *stack_b);
void	exit_with_error(int *nums, t_stack *stack_a, t_stack *stack_b);

#endif