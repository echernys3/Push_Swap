/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:58:37 by echernys          #+#    #+#             */
/*   Updated: 2025/01/21 15:57:21 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stacks **stacks)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*stacks)->stack_a == NULL || (*stacks)->stack_a->next == NULL)
		return ;
	last = ft_lstlast((*stacks)->stack_a);
	temp = (*stacks)->stack_a->next;
	last->next = (*stacks)->stack_a;
	(*stacks)->stack_a->next = NULL;
	(*stacks)->stack_a = temp;
	(*stacks)->operations++;
	ft_printf("ra\n");
}

void	rb(t_stacks **stacks)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*stacks)->stack_b == NULL || (*stacks)->stack_b->next == NULL)
		return ;
	last = ft_lstlast((*stacks)->stack_b);
	temp = (*stacks)->stack_b->next;
	last->next = (*stacks)->stack_b;
	(*stacks)->stack_b->next = NULL;
	(*stacks)->stack_b = temp;
	(*stacks)->operations++;
	ft_printf("rb\n");
}

static void	copy_ra(t_stacks **stacks)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*stacks)->stack_a == NULL || (*stacks)->stack_a->next == NULL)
		return ;
	last = ft_lstlast((*stacks)->stack_a);
	temp = (*stacks)->stack_a->next;
	last->next = (*stacks)->stack_a;
	(*stacks)->stack_a->next = NULL;
	(*stacks)->stack_a = temp;
}

static void	copy_rb(t_stacks **stacks)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*stacks)->stack_b == NULL || (*stacks)->stack_b->next == NULL)
		return ;
	last = ft_lstlast((*stacks)->stack_b);
	temp = (*stacks)->stack_b->next;
	last->next = (*stacks)->stack_b;
	(*stacks)->stack_b->next = NULL;
	(*stacks)->stack_b = temp;
}

void	rr(t_stacks **stacks)
{
	copy_ra(stacks);
	copy_rb(stacks);
	(*stacks)->operations++;
	ft_printf("rr\n");
}
