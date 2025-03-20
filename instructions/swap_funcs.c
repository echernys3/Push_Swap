/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:38:15 by echernys          #+#    #+#             */
/*   Updated: 2025/03/06 18:46:32 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **head)
{
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
	ft_printf("sa\n");
	temp = NULL;
}

void	sb(t_stack **head)
{
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
	ft_printf("sb\n");
	temp = NULL;
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
	temp = NULL;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	copy_swap(stack_a);
	copy_swap(stack_b);
	ft_printf("ss\n");
}

// A voir si je veux laisser le head->next == NULL 
// partout ou pas, car ça pourrait casser le code pr que 2 nodes.