/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echernys <echernys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:58:37 by echernys          #+#    #+#             */
/*   Updated: 2024/12/05 18:19:59 by echernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	rr(t_stacks **stacks)
{
	
}
