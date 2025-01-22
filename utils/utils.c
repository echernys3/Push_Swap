/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:24:31 by echernys          #+#    #+#             */
/*   Updated: 2025/01/22 16:46:38 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_atoi(const char *str, t_stacks **stacks)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error(stacks, ERR_DATA);
		res = res * 10 + (str[i] - '0');
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
			runner = runner->next;
		}
		current = current->next;
	}
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

t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

size_t	ps_stacksize(t_stack *lst)
{
	unsigned int	counter;

	counter = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}
