/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:43 by echernys          #+#    #+#             */
/*   Updated: 2024/12/10 14:47:38 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freer(t_stack *stack)
{
	t_stack	temp;

	temp = stack;
	while (stack != NULL)
	{
		temp = stack -> next;
		free(stack);
		stack = temp;
	}
}

void	push_swap(t_stacks **stacks)
{
	if ((*stacks)->size_a == 3)
		return ;
	while ((*stacks)->size_a > 3)
	{
		if ((*stacks)->stack_a->index > (*stacks)->stack_b->index
			|| !(*stacks)->stack_b)
		{
			if ((*stacks)->stack_a->index < (*stacks)->stack_a->next->index)
				pb(stacks);
			else if ((*stacks)->stack_a->next->index
				> (*stacks)->stack_a->next->next->index)
			{
				
			}
			else
		}
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_stacks	**stacks;
	t_stack		*newnode;

	i = 1;
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (1);
	while (argv[i][0])
	{
		newnode = create_node(argv[i][0]);
		ft_lstadd_back((*stacks)->stack_a, newnode);
		i++;
	}
	push_swap(stacks);
	ft_printf("%d", (*stacks)->operations);
	freer((*stacks)->stack_a);
	free(**stacks);
}
