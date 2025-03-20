/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:25:49 by echernys          #+#    #+#             */
/*   Updated: 2025/03/17 16:11:17 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_freer(int *nums, t_stack *stack_a, t_stack *stack_b)
{
	if (nums)
	{
		free(nums);
	}
	if (stack_a)
		ps_clearlst(&stack_a);
	if (stack_b)
		ps_clearlst(&stack_b);
}

void	exit_on_split(int *nums, char **temp, int size)
{
	split_freer(temp, size);
	exit_with_error(nums, NULL, NULL);
}

void	exit_with_error(int *nums, t_stack *stack_a, t_stack *stack_b)
{
	ps_freer(nums, stack_a, stack_b);
	ft_printf("Error\n");
	exit(1);
}
