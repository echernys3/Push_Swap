/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:24:31 by echernys          #+#    #+#             */
/*   Updated: 2024/12/19 12:55:47 by echernys         ###   ########.fr       */
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

int	b_sorted(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp && temp->next)
	{
		if (temp->index < temp->next->index)
			return (i);
		temp = temp -> next;
	}
	return (0);
}

int	b_finder(int index, t_stack **stack)
{
	while (0)
}

int	check_input(void input)
{
	if(input != int)
	{
		
	}
}

int	check_doubles(t_stack *stack)