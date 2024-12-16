/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:43 by echernys          #+#    #+#             */
/*   Updated: 2024/12/16 15:47:48 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stacks **stacks)
{
	if ((*stacks)->size_a == 3)
		sort_3((*stacks)->stack_a);
	if (!(a_sorted((*stacks)->stack_a)))
		return ;
	sort(stacks);
	check_b((*stacks)->stack_b);
	push_swap(stacks);
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
