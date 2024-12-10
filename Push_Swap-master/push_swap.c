/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:43 by echernys          #+#    #+#             */
/*   Updated: 2024/12/05 16:26:53 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**calc_solution()
{
	

	
}

void push_swap()
{
	calc_solution();
	ft_printf();
	ft_printf();
}

int	main(int argc, char **argv)
{
	int		i;
	t_stacks	**stacks;
	t_stack	*newnode;

	i = 1;
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (1);
	while (argv[i][0])
	{
		newnode = create_node(argv[i][0]);
		ft_lstaddback((*stacks)->stack_a, newnode);
		i++;
	}
	freer(stacks);
}