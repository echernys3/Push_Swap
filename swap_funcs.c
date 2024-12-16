/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:04 by echernys          #+#    #+#             */
/*   Updated: 2024/12/10 13:30:13 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **head, t_stacks **stacks)
{
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
	(*stacks)->operations++;
	ft_printf("sa\n");
}

void	sb(t_stack **head, t_stacks **stacks)
{
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
	(*stacks)->operations++;
	ft_printf("sb\n");
}

static void	copy_swap(t_stack **head)
{
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
}

void	ss(t_stacks *stacks)
{
	copy_swap(&stacks->stack_a);
	copy_swap(&stacks->stack_b);
	stacks->operations++;
	ft_printf("ss\n");
}

// A voir si je veux laisser le head->next == NULL 
//partout ou pas, car ça pourrait casser le code pr que 2 nodes.