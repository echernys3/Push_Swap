/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:28:45 by echernys          #+#    #+#             */
/*   Updated: 2024/12/05 15:41:38 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list{

	int	number;
	int index;
	struct t_stack *next;
	
} t_stack;

typedef struct s_list
{
	t_stack	stack_a;
	t_stack	stack_b;
	int	size_a;
	int	size_b;
	int	operations;
} t_stacks;