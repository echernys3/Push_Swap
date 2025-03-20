/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:37:01 by echernys          #+#    #+#             */
/*   Updated: 2025/03/11 15:18:42 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_clearlst(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		current->next = NULL;
		free(current);
		current = next;
	}
	*head = NULL;
}

static t_stack	*ps_lstnew(int *nums, int i)
{
	t_stack	*newhead;

	newhead = malloc(sizeof(t_stack));
	if (!newhead)
		exit(1);
	newhead->num = nums[i];
	newhead->next = NULL;
	return (newhead);
}

void	ps_lstaddfront(t_stack **head, t_stack *newnode)
{
	if (!newnode)
		return ;
	if (*head)
		newnode->next = *head;
	*head = newnode;
}

void	ps_lstaddback(t_stack **head, t_stack *newnode)
{
	t_stack	*temp;

	if (!newnode)
		return ;
	temp = *head;
	if (!*head)
		*head = newnode;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = newnode;
	}
}

t_stack	*create_lst(int *nums, int size)
{
	t_stack	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		ps_lstaddback(&stack_a, ps_lstnew(nums, i));
		i++;
	}
	return (stack_a);
}
