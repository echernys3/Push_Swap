/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:46:21 by echernys          #+#    #+#             */
/*   Updated: 2024/12/10 14:46:31 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_min(t_stack *stack, t_stacks **stacks)
{
	if (stack->index == 1)
	{
		pb(stacks);
	}
	if (ft_lstlast(stack)->index == 1)
	{
		rrr(stacks);
		pb(stacks);
	}
	
}
