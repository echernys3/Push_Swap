/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:43 by echernys          #+#    #+#             */
/*   Updated: 2025/02/17 18:15:57 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if ((*stacks)->stack_b != NULL)
		freer((*stacks)->stack_b);
	freer((*stacks)->stack_a);
	free(stacks);
}

void	push_swap(t_stacks **stacks)
{
	if ((*stacks)->size_a < 3)
	{
		if ((*stacks)->size_a == 2 && (*stacks)->stack_a->index
			< (*stacks)->stack_a->next->index)
			sa(&(*stacks)->stack_a, stacks);
		return ;
	}
	if ((*stacks)->size_a == 3)
		sort_3((*stacks)->stack_a, stacks);
	if (!(a_sorted((*stacks)->stack_a)))
		return ;
	sort((*stacks)->stack_a, stacks);
	push_swap(stacks);
}

int	main(int argc, char **argv)
{
	int			i;
	t_stacks	*stacks;
	t_stack		*newnode;

	i = 1;
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		exit_error(&stacks, ERR_ALLOC);
	(*stacks).stack_a = NULL;
	(*stacks).stack_b = NULL;
	(*stacks).size_a = 0;
	(*stacks).size_b = 0;
	(*stacks).operations = 0;
	ft_printf("Checkpoint 1!");
	while (i < argc)
	{
		newnode = create_node(&stacks, argv[i]);
		ps_stackadd_back(&(*stacks).stack_a, newnode);
		i++;
	}
	ft_printf("Checkpoint 3!");
	index_t_stack(&stacks, (*stacks).stack_a);
	check_doubles((*stacks).stack_a, &stacks);
	push_swap(&stacks);
	ft_printf("%d", (*stacks).operations);
	exit_error(&stacks, 0);
}
