/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:43 by echernys          #+#    #+#             */
/*   Updated: 2025/01/21 16:08:06 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int errnum)
{
	if (errnum == ERR_ALLOC)
		ft_printf("Allocation error!");
	if (errnum == ERR_DATA)
		ft_printf("Invalid Data, non digit detected!");
	if (errnum == ERR_DOUBLES)
		ft_printf("Invalid Data, doubles detected!");
}

void	exit_error(t_stacks **stacks, int errnum)
{
	if (errnum)
		print_error(errnum);
	if ((*stacks)->stack_b)
		freer((*stacks)->stack_b);
	freer((*stacks)->stack_a);
	free(**stacks);
}

void	push_swap(t_stacks **stacks)
{
	if ((*stacks)->size_a == 3)
		sort_3((*stacks)->stack_a);
	if (!(a_sorted((*stacks)->stack_a)))
		return ;
	sort(stacks);

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
		exit_error(stacks, ERR_ALLOC);
	while (argc--)
	{
		newnode = create_node(argv[i]);
		ft_lstadd_back((*stacks)->stack_a, newnode);
		i++;
	}
	index_t_stack((*stacks)->stack_a);
	if (check_doubles(*stacks)->stack_a)
		push_swap(stacks);
	ft_printf("%d", (*stacks)->operations);
	exit_error(stacks, 0);
}
