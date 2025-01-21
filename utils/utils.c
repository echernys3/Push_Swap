/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:24:31 by echernys          #+#    #+#             */
/*   Updated: 2025/01/21 16:01:48 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_sorted(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp && temp->next)
	{
		if (temp->index > temp->next->index)
			return (i);
		i++;
		temp = temp -> next;
	}
	return (0);
}


int	ps_atoi(const char *str, t_stacks **stacks)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			exit_error(stacks, ERR_DATA);
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
// Convert to int, while checking for invalid values

void	check_doubles(t_stack *stack, t_stacks **stacks)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->number == runner->number)
				exit_error(stacks, ERR_DOUBLES);
			runner->next;
		}
		current->next;
	}
	return (false);
}

void	freer(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack != NULL)
	{
		temp = stack -> next;
		free(stack);
		stack = temp;
	}
}
